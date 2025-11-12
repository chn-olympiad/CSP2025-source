#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
#define left wshnl
#define right wkqnl
using namespace std;
const int N=4e5+5;
ull base=131,tH[N];
int n,q;
vector<ull> s[N][2];
int len[N][2],id[N];
string rs[N][2];
int lcp(int i,bool x,int j,bool y){
    int l=0,r=min(len[i][x],len[j][y]),mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(s[i][x][mid]==s[j][y][mid]){
            ans=mid;l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
bool cmp1(int i,int j){
    int lc=lcp(i,0,j,0);
    if(lc==min(len[i][0],len[j][0]))return len[i][0]<=len[j][0];
    return rs[i][0][lc]<rs[j][0][lc];
}
unordered_map<ull,int>mp;int num;
set<ull>st;
int pretot,tot,cnt[N*15],left[N*15],right[N*15],rt[N*15];
void new_version(){
    pretot=tot;
}
int new_node(int p){
    if(p>pretot)return p;
    int tmp=++tot;
    left[tmp]=left[p];
    right[tmp]=right[p];
    cnt[tmp]=cnt[p];
    return tmp;
}
int build(int l,int r){
    if(l==r)return ++tot;
    int mid=(l+r)>>1;
    int p=++tot;
    left[p]=build(l,mid);
    right[p]=build(mid+1,r);
    return p;
}
int upd(int k,int s,int t,int p){
    p=new_node(p);
    if(s==t){
        cnt[p]++;
        return p;
    }
    int mid=(s+t)>>1;
    if(k<=mid)left[p]=upd(k,s,mid,left[p]);
    else right[p]=upd(k,mid+1,t,right[p]);
    cnt[p]=cnt[left[p]]+cnt[right[p]];
    return p;
}
int query(int k,int s,int t,int p){
    if(s==t)return cnt[p];
    int mid=(s+t)>>1;
    if(k<=mid)return query(k,s,mid,left[p]);
    return query(k,mid+1,t,right[p]);
}
int findpos(int i){
    int l=1,r=n,mid,ans=n;
    while(l<=r){
        mid=(l+r)>>1;
        if(cmp1(i,id[mid])){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int findlg(int i,int pos,int x){
    int l=1,r=pos,mid,ans=pos+1;
    while(l<=r){
        mid=(l+r)>>1;
        if(lcp(id[mid],0,i,0)>=x){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
/*
int findrg(int i,int pos,int x){
    int l=pos,r=n,mid,ans=pos;
    while(l<=r){
        mid=(l+r)>>1;
        if(lcp(id[mid],0,i,0)>=x){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}*/
int main(){
    ios::sync_with_stdio(false);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        int l,r;
        for(l=0;l<x.size()&&x[l]==y[l];l++);
        for(r=x.size()-1;r>=0&&x[r]==y[r];r--);
        ull H=0;s[i][0].push_back(0);s[i][1].push_back(0);
        for(int j=r;j>=0;j--){
            H*=base;H+=x[j];
            s[i][0].push_back(H);
            rs[i][0]+=x[j];
        }
        H=0;
        for(int j=l;j<x.size();j++){
            H*=base;H+=y[j];
            s[i][1].push_back(H);
            rs[i][1]+=y[j];
        }
        len[i][0]=r+1;len[i][1]=x.size()-l;
        st.insert(H);tH[i]=H;
        id[i]=i;
    }
    for(auto i:st)mp[i]=++num;
    sort(id+1,id+n+1,cmp1);
    //for(int i=1;i<=n;i++)cout<<rs[id[i]][0]<<endl;
    rt[0]=build(1,num);
    for(int i=1;i<=n;i++){
        new_version();
        rt[i]=new_node(rt[i-1]);
        ull H=tH[id[i]];
        rt[i]=upd(mp[H],1,num,rt[i]);
        //cout<<"ADD "<<i<<" "<<H<<endl;
    }
    //return 0;
    for(int i=1+n;i<=n+q;i++){
        string x,y;
        cin>>x>>y;
        int l,r;
        for(l=0;l<x.size()&&x[l]==y[l];l++);
        for(r=x.size()-1;r>=0&&x[r]==y[r];r--);
        ull H=0;s[i][0].push_back(0);s[i][1].push_back(0);
        for(int j=r;j>=0;j--){
            H*=base;H+=x[j];
            s[i][0].push_back(H);
            rs[i][0]+=x[j];
        }
        H=0;
        for(int j=l;j<x.size();j++){
            H*=base;H+=y[j];
            s[i][1].push_back(H);
            rs[i][1]+=y[j];
        }
        len[i][0]=r+1;len[i][1]=x.size()-l;
        int pos=findpos(i);
        if(!pos){
            cout<<0<<"\n";
            continue;
        }
        //cout<<"SUC "<<pos<<endl;
        int L=findlg(i,pos,r-l+1);
        //cout<<"POS "<<pos<<" "<<L<<" "<<endl;
        //return 0;
        H=0;
        int ans=0;
        for(int j=l;j<x.size();j++){
            H*=base;H+=y[j];
            if(j>=r&&mp.count(H)){
                ans+=query(mp[H],1,num,rt[pos])-query(mp[H],1,num,rt[L-1]);
                //cout<<"QU "<<H<<" "<<query(mp[H],1,num,rt[pos])-query(mp[H],1,num,rt[L-1])<<endl;
            }
        }
        cout<<ans<<"\n";
    }
    //for(int i=1;i<=n;i++)cout<<rs[id[i]][0]<<endl;
    return 0;
}