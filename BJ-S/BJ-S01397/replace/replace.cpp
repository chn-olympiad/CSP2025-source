#include <bits/stdc++.h>
using namespace std;

int n,q;
const int N=2e6+5;
string s1[N],s2[N];
int cnt;

struct node{
    long long a,b;
    int id;
    string x,y;
}chg[N*2];

const int base=1331,mod=998244353;
long long calc(string s,int bg,int ed){
    long long hsh=0;
    for(int i=bg;i<=ed;i++){
        hsh=(hsh*base)%mod+s[i]-'a'+1;
        hsh%=mod;
    }
    return hsh;
}

bool cmp(node a,node b){
    if(a.a==b.a) return a.b<b.b;
    else return a.a<b.a;
}

int rt[N],rt_cnt;
int rta[N],rtb[N],rta2[N],rtb2[N];
int ch[N][26];
vector<int> w[N];
int ind;
int rt2[N],rt_cnt2;
int ch2[N][26];
vector<int> w2[N];
int ind2;

void insert(int root,string s,int id){
    int p=root;
    //cout<<p<<' ';
    for(int i=0;i<s.size();i++){
        if(ch[p][s[i]-'a']==0){
            ch[p][s[i]-'a']=++ind;
        }
        p=ch[p][s[i]-'a'];
    }
    //cout<<p<<' '<<id<<"gets"<<endl;
    w[p].push_back(id);
}
void insert2(int root,string s,int id){
    int p=root;
    for(int i=0;i<s.size();i++){
        if(ch2[p][s[i]-'a']==0){
            ch2[p][s[i]-'a']=++ind2;
        }
        p=ch2[p][s[i]-'a'];
    }
    w2[p].push_back(id);
}

int flg[N],num[N];
char c;
int flag;
void dfs(int root,string s){
    int len=s.size();
    int p=root;
    for(int j=0;j<w[p].size();j++){
        //cout<<"lxl"<<w[p][j]<<endl;
        flg[w[p][j]]++;
        if(flag) num[w[p][j]]=len;
    }
    int dep=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=c) flag=0;
        dep++;
        p=ch[p][s[i]-'a'];
        if(p==0) return ;
        for(int j=0;j<w[p].size();j++){
            //cout<<"lxl"<<w[p][j]<<endl;
            flg[w[p][j]]++;
            if(flag) num[w[p][j]]=len-dep+1;
        }
    }
}
void dfs2(int root,string s){
    int p=root;
    for(int j=0;j<w2[p].size();j++){
        flg[w2[p][j]]++;
    }
    for(int i=0;i<s.size();i++){
        p=ch2[p][s[i]-'a'];
        if(p==0) return ;
        for(int j=0;j<w2[p].size();j++){
            flg[w2[p][j]]++;
        }
    }
}

string t1,t2;

int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        int begin=-1,ed=-1;
        int l1=t1.size();
        int l2=t2.size();
        for(int j=0;j<min(l1,l2);j++){
            if(t1[j]!=t2[j]){
                begin=j;
                break;
            }
        }
        if(begin==-1){
            begin=min(l1,l2)+1;
        }
        for(int j=0;j<min(l1,l2);j++){
            if(t1[l1-1-j]!=t2[l2-1-j]){
                ed=j;
                break;
            }
        }
        if(ed==-1){
            ed=min(l1,l2)+1;
        }
        if(begin==min(l1,l2)+1&&ed==min(l1,l2)+1){
            if(l1<l2){
                chg[++cnt].a=0,chg[cnt].b=calc(t2,l1,l2-1);
                for(int j=l1-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t2[j];
                }
            }
            else if(l1>l2){
                chg[++cnt].a=calc(t1,l2,l1-1),chg[cnt].b=0;
                for(int j=l2-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t1[j];
                }
            }
            else if(l1==l2){
                chg[++cnt].x=t1;
            }
        }
        else if(begin==min(l1,l2)+1){
            if(l1<l2){
                chg[++cnt].a=0,chg[cnt].b=calc(t2,l1,l2-1);
                for(int j=l1;j<l2;j++){
                    chg[cnt].y=chg[cnt].y+t2[j];
                }
            }
            else if(l1>l2){
                chg[++cnt].a=calc(t1,l2,l1-1),chg[cnt].b=0;
                for(int j=l2;j<l1;j++){
                    chg[cnt].y=chg[cnt].y+t1[j];
                }
            }
        }
        else if(ed==min(l1,l2)+1){
            if(l1<l2){
                chg[++cnt].a=0,chg[cnt].b=calc(t2,l1,l2-1);
                for(int j=l2-l1-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t2[j];
                }
            }
            else if(l1>l2){
                chg[++cnt].a=calc(t1,l2,l1-1),chg[cnt].b=0;
                for(int j=l1-l2-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t1[j];
                }
            }
        }
        else{
            chg[++cnt].a=calc(t1,begin,l1-1-ed);
            chg[cnt].b=calc(t2,begin,l2-1-ed);
            for(int j=begin-1;j>0;j--){
                chg[cnt].x=chg[cnt].x+t1[j];
            }
            for(int j=l2-ed;j<l2;j++){
                chg[cnt].y=chg[cnt].y+t1[j];
            }
        }
        chg[cnt].id=i;
        //cout<<"change"<<' '<<chg[cnt].a<<' '<<chg[cnt].b<<' '<<chg[cnt].x<<' '<<chg[cnt].y<<' '<<begin<<' '<<ed<<endl;
    }

    sort(chg+1,chg+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if(i==1||(chg[i-1].a!=chg[i].a||chg[i-1].b!=chg[i].b)){
            rt[++rt_cnt]=++ind;
            rta[rt_cnt]=chg[i].a,rtb[rt_cnt]=chg[i].b;
            rt2[++rt_cnt2]=++ind2;
            rta2[rt_cnt2]=chg[i].a,rtb2[rt_cnt2]=chg[i].b;
            insert(rt[rt_cnt],chg[i].x,chg[i].id);
            insert2(rt2[rt_cnt2],chg[i].y,chg[i].id);
        }
        else{
            insert(rt[rt_cnt],chg[i].x,chg[i].id);
            insert2(rt2[rt_cnt2],chg[i].y,chg[i].id);
        }
    }

    while(q--){
        flag=1;
        cin>>t1>>t2;
        int begin=-1,ed=-1;
        int l1=t1.size();
        int l2=t2.size();
        for(int j=0;j<min(l1,l2);j++){
            if(t1[j]!=t2[j]){
                begin=j;
                break;
            }
        }
        if(begin==-1){
            begin=min(l1,l2)+1;
        }
        for(int j=0;j<min(l1,l2);j++){
            if(t1[l1-1-j]!=t2[l2-1-j]){
                ed=j;
                break;
            }
        }
        if(ed==-1){
            ed=min(l1,l2)+1;
        }
        if(begin==min(l1,l2)+1&&ed==min(l1,l2)+1){
            if(l1<l2){
                chg[++cnt].a=0,chg[cnt].b=calc(t2,l1,l2-1);
                c=t2[l1];
                for(int j=l1;j<=l2-1;j++) if(t2[j]!=c) flag=0;
                for(int j=l1-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t2[j];
                }
            }
            else if(l1>l2){
                chg[++cnt].a=calc(t1,l2,l1-1),chg[cnt].b=0;
                c=t1[l2];
                for(int j=l2;j<=l1-1;j++) if(t1[j]!=c) flag=0;
                for(int j=l2-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t1[j];
                }
            }
            else if(l1==l2){
                chg[++cnt].x=t1;
            }
        }
        else if(begin==min(l1,l2)+1){
            if(l1<l2){
                chg[++cnt].a=0,chg[cnt].b=calc(t2,l1,l2-1);
                c=t2[l1];
                for(int j=l1;j<=l2-1;j++) if(t2[j]!=c) flag=0;
                for(int j=l1;j<l2;j++){
                    chg[cnt].y=chg[cnt].y+t2[j];
                }
            }
            else if(l1>l2){
                chg[++cnt].a=calc(t1,l2,l1-1),chg[cnt].b=0;
                c=t1[l2];
                for(int j=l2;j<=l1-1;j++) if(t1[j]!=c) flag=0;
                for(int j=l2;j<l1;j++){
                    chg[cnt].y=chg[cnt].y+t1[j];
                }
            }
        }
        else if(ed==min(l1,l2)+1){
            if(l1<l2){
                chg[++cnt].a=0,chg[cnt].b=calc(t2,l1,l2-1);
                for(int j=l2-l1-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t2[j];
                }
            }
            else if(l1>l2){
                chg[++cnt].a=calc(t1,l2,l1-1),chg[cnt].b=0;
                for(int j=l1-l2-1;j>=0;j--){
                    chg[cnt].x=chg[cnt].x+t1[j];
                }
            }
        }
        else{
            chg[++cnt].a=calc(t1,begin,l1-1-ed);
            chg[cnt].b=calc(t2,begin,l2-1-ed);
            for(int j=begin-1;j>=0;j--){
                chg[cnt].x=chg[cnt].x+t1[j];
            }
            for(int j=l2-ed;j<l2;j++){
                chg[cnt].y=chg[cnt].y+ t1[j];
            }
        }
        //cout<<"change"<<' '<<chg[cnt].a<<' '<<chg[cnt].b<<' '<<chg[cnt].x<<' '<<chg[cnt].y<<' '<<begin<<' '<<ed<<endl;
        int stp=1;
        for(int j=20;j>=0;j--){
            int nxt=stp+(1<<j);
            if((nxt<=rt_cnt)&&(rta[nxt]<chg[cnt].a||(rta[nxt]==chg[cnt].a&&rtb[nxt]<=chg[cnt].b))){
                stp=nxt;
            }
        }
        //cout<<rta[stp]<<' '<<rtb[stp]<<endl;
        if(rta[stp]!=chg[cnt].a||rtb[stp]!=chg[cnt].b) cout<<0<<endl;
        else{
            if(chg[cnt].b!=0||chg[cnt].a!=0) flag=0;
            for(int i=0;i<chg[cnt].x.size();i++){
                if(chg[cnt].x[i]!=c) flag=0;
            }
            for(int i=1;i<=n;i++) flg[i]=0,num[i]=1;
            dfs(rt[stp],chg[cnt].x);
            dfs2(rt2[stp],chg[cnt].y);
            int ans=0;
            for(int i=1;i<=n;i++){
                if(flg[i]==2) ans+=num[i];
            }
            cout<<ans<<endl;
        }
    }


    return 0;
}