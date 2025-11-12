#include<bits/stdc++.h>
using namespace std;
const int L=2000+7,N=1e4+7;
int n,q;
struct node{
    string s[2];
    int len;
}p[N];
struct ACAM{
    int tr[L][26],tot,fail[L];
    bitset<N>pos[L];
    inline void ins(string s,int id){
        int u=0;
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            if(!tr[u][c])tr[u][c]=++tot;
            u=tr[u][c];
        }
        pos[u].set(id);
    }
    inline void build(){
        queue<int>q;
        for(int i=0;i<26;i++){
            if(tr[0][i])q.push(tr[0][i]);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            pos[t]|=pos[fail[t]];
            for(int i=0;i<26;i++){
                if(tr[t][i]){
                    fail[tr[t][i]]=tr[fail[t]][i];
                    q.push(tr[t][i]);
                }else{
                    tr[t][i]=tr[fail[t]][i];
                }
            }
        }
    }
}a[2];
string t[2];
bitset<N>ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>p[i].s[0]>>p[i].s[1];
        p[i].len=p[i].s[0].size();
    }
    sort(p+1,p+1+n,[](const node &a,const node &b){
        return a.len<b.len;
    });
    for(int i=1;i<=n;i++){
        a[0].ins(p[i].s[0],i);
        a[1].ins(p[i].s[1],i);
    }
    a[0].build(),a[1].build();
    while(q--){
        ans.reset();
        cin>>t[0]>>t[1];
        int lcs=0,lcp=0;
        for(int i=0;i<t[0].size();i++){
            if(t[0][i]!=t[1][i]){
                lcp=i-1;
                break;
            }
        }
        for(int i=(int)t[0].size()-1;i>=0;i--){
            if(t[0][i]==t[1][i])continue;
            lcs=i+1;
            break;
        }
        int ps[2]={0,0};
        for(int i=0;i<t[0].size();i++){
            for(int j=0;j<2;j++){
                ps[j]=a[j].tr[ps[j]][t[j][i]-'a'];
            }
            if(i>=lcs){
                int x=i-lcp;
                int l=1,r=n;
                while(l<r){
                    int mid=l+r>>1;
                    if(p[mid].len>=x)r=mid;
                    else l=mid+1;
                }
                ans|=((a[0].pos[ps[0]]&a[1].pos[ps[1]])>>(l-2));
            }
        }
        cout<<ans.count()<<'\n';
    }
    return 0;
}