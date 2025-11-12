#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5,M=1e4+5;
ll ans;
int n,q;
char chs[N][M],chf[N][M],chm[M],chg[M];
void check(int adr,int id)
{
    char chl[M];
    for(int i=1;i<=strlen(chm+1);i++) chl[i]=chm[i];
    for(int i=adr;i<=adr+strlen(chs[id]+1)-1;i++) if(chs[id][i-adr+1]!=chl[i]) return;
    for(int i=adr;i<=adr+strlen(chs[id]+1)-1;i++) chl[i]=chf[id][i-adr+1];
    for(int i=1;i<=strlen(chg+1);i++) if(chl[i]!=chg[i]) return;
    if(strlen(chl+1)!=strlen(chg+1)) return;
    ans++;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) cin>>chs[i]+1>>chf[i]+1;
    while(q--)
    {
        ans=0;
        cin>>chm+1>>chg+1;
        int l=strlen(chm+1);
        for(int i=1;i<=l;i++)
        for(int j=1;j<=n;j++) if(chs[j][1]==chm[i]) check(i,j);
        printf("%lld\n",ans);
    }
    return 0;
}
