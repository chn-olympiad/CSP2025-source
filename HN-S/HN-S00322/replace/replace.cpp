#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=5e4+5,M=1e6+5;
const ull base=100;
string s[N],t[N],x,y;
int n,q,pre[N],sub[N];
ull phash[N],shash[N],Shash[N],thash[N],qphash[M],qshash[M],qxhash,qyhash;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>t[i];
        if(s[i]==t[i])
        {
            pre[i]=-1;
            continue;
        }
        pre[i]=0;
        while(s[i][pre[i]]==t[i][pre[i]])phash[i]=phash[i]*base+s[i][pre[i]],pre[i]++;
        sub[i]=((int)s[i].size())-1;
        while(s[i][sub[i]]==t[i][sub[i]])shash[i]=shash[i]*base+s[i][sub[i]],sub[i]--;
        for(int j=pre[i];j<=sub[i];j++)Shash[i]=Shash[i]*base+s[i][j];
        for(int j=pre[i];j<=sub[i];j++)thash[i]=thash[i]*base+t[i][j];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        int qpre=0,qsub=((int)x.size())-1;
        while(x[qpre]==y[qpre])qpre++;
        while(x[qsub]==y[qsub])qsub--;
        ull bsm=1;
        qphash[qpre]=qshash[qsub]=0;
        for(int i=qpre-1;~i;i--)qphash[i]=qphash[i+1]+x[i]*bsm,bsm*=base;
        bsm=1;
        for(int i=qsub+1;i<(int)x.size();i++)qshash[i]=qshash[i-1]+x[i]*bsm,bsm*=base;
        for(int i=qpre;i<=qsub;i++)qxhash=qxhash*base+x[i];
        for(int i=qpre;i<=qsub;i++)qyhash=qyhash*base+y[i];
        int tmp=0;
        // cout<<qpre<<" "<<qsub<<" "<<qxhash<<" "<<qyhash<<"\n";
        for(int j=1;j<=n;j++)
        {
            if(pre[j]>qpre||(int)s[j].size()-sub[j]>(int)x.size()-qsub)continue;
            if(Shash[j]!=qxhash||thash[j]!=qyhash)continue;
            // cout<<sub[j]<<" "<<qshash[qsub+(int)s[j].size()-sub[j]-1]<<" "<<shash[j]<<"\n";
            if(qphash[qpre-pre[j]]!=phash[j]||qshash[qsub+(int)s[j].size()-sub[j]-1]!=shash[j])continue;
            tmp++;
        }
        cout<<tmp<<"\n";
    }
    return 0;
}