#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool st;
const int N=5e6+5,M=2e5+5;
const ll mod1=1e9+7,bas1=13331;
const ll mod2=998244353,bas2=131;
ll trans(ll x,ll y){
    return y*mod1+x;
}
int n,m;char aa[N],bb[N];
ll pre[M],suf[M],fac1[N],fac2[N],ha[M],hb[M];
ll aha[N],bha[N],ahb[N],bhb[N];
void pree(){
    fac1[0]=fac2[0]=1;
    for(int i=1;i<N;i++){
        fac1[i]=fac1[i-1]*bas1%mod1;
        fac2[i]=fac2[i-1]*bas2%mod2;
    }
}
void gethash(){
    int n=strlen(aa+1);
    for(int i=1;i<=n;i++){
        aha[i]=(aha[i-1]*bas1+int(aa[i]))%mod1;
        ahb[i]=(ahb[i-1]*bas2+int(aa[i]))%mod2;
        bha[i]=(bha[i-1]*bas1+int(bb[i]))%mod1;
        bhb[i]=(bhb[i-1]*bas2+int(bb[i]))%mod2;
    }
}
ll qa(int l,int r){
    if(l>r)return 0;
    ll ha=(aha[r]-aha[l-1]*fac1[r-l+1]%mod1+mod1)%mod1;
    ll hb=(ahb[r]-ahb[l-1]*fac2[r-l+1]%mod2+mod2)%mod2;
    return trans(ha,hb);
}
ll qb(int l,int r){
    if(l>r)return 0;
    ll ha=(bha[r]-bha[l-1]*fac1[r-l+1]%mod1+mod1)%mod1;
    ll hb=(bhb[r]-bhb[l-1]*fac2[r-l+1]%mod2+mod2)%mod2;
    return trans(ha,hb);
}
void solve1(){
    for(int i=1;i<=n;i++){
        scanf("%s",aa+1);
        scanf("%s",bb+1);
        int k=strlen(aa+1),st=-1,ed=-1;
        for(int j=1;j<=k;j++)
        if(aa[j]!=bb[j]){st=j;break;}
        for(int j=k;j;j--)
        if(aa[j]!=bb[j]){ed=j;break;}
        if(st==-1)continue;
        else{
            gethash();ha[i]=qa(st,ed);hb[i]=qb(st,ed);
            pre[i]=qa(1,st-1);suf[i]=qa(ed+1,k);
        }
        //cout<<pre[i]<<" "<<suf[i]<<endl;
    }
    while(m--){
        scanf("%s",aa+1);scanf("%s",bb+1);
        int k=strlen(aa+1),st=-1,ed=-1;
        for(int j=1;j<=k;j++)
        if(aa[j]!=bb[j]){st=j;break;}
        for(int j=k;j;j--)
        if(aa[j]!=bb[j]){ed=j;break;}gethash();
        //cout<<st<<" "<<ed<<endl;
        set<ll> A,B;int ss=0;
        for(int i=1;i<=st;i++)A.insert(qa(i,st-1));
        for(int i=ed;i<=k;i++)B.insert(qa(ed+1,i));
        for(int i=1;i<=n;i++){
            if(ha[i]!=qa(st,ed)||hb[i]!=qb(st,ed))continue;
            if(A.find(pre[i])!=A.end()&&B.find(suf[i])!=B.end())ss++;
        }
        printf("%d\n",ss);
    }
}
bool ed;
int main(){
    //freopen("replace2.in","r",stdin);
    //freopen("1.out","w",stdout);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);pree();
    solve1();
    return 0;
}