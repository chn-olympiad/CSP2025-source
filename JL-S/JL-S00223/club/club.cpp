#include<bits/stdc++.h>
using namespace std;
int n,m,t,x=1,y=1,z=1,a[100010],b[10010],c[100010],ai[500050],bi[500050],ci[500050],cont=-1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        x=1;
        y=1;
        z=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            int miab=1e7,miac=1e7,miba=1e7,mibc=1e7,mica=1e7,micb=1e7;
            int mab,mac,mba,mbc,mca,mcb;
            if(a[i]>=b[i]&&a[i]>=c[i])
            {
                if(x<=n/2)
                {
                    ai[x]=i;
                    x++;
                    ans+=a[i];
                }
                else
                {
                    for(int j=1;j<x;j++){
                        if(a[ai[j]]-b[ai[j]]<miab)
                        {
                            miab=a[ai[j]]-b[ai[j]];
                            mab=j;
                        }
                        if(a[ai[j]]-c[ai[j]]<miac)
                        {
                            miac=a[ai[j]]-c[ai[j]];
                            mac=j;
                        }
                    }
                    if(a[i]>=miab&&miab<=miac){
                        bi[y]=ai[mab];
                        ai[mab]=i;
                        y++;
                        ans-=miab;
                        ans+=a[i];
                    }
                    else if(a[i]>=miac&&miab>miac){
                        ci[z]=ai[mac];
                        ai[mac]=i;
                        z++;
                        ans-=miac;
                        ans+=a[i];
                    }
                    else
                    {
                        if(b[i]>=c[i]){
                            bi[y]=i;
                            y++;
                            ans+=b[i];
                        }
                        else{
                            ci[z]=i;
                            z++;
                            ans+=c[i];
                        }
                    }
                }
            }
            else if(a[i]<=b[i]&&b[i]>=c[i])
            {
                if(y<=n/2)
                {
                    bi[y]=i;
                    y++;
                    ans+=b[i];
                }
                else
                {
                    for(int j=1;j<y;j++){
                        if(b[bi[j]]-a[bi[j]]<miba)
                        {
                            miba=b[bi[j]]-a[bi[j]];
                            mba=j;
                        }
                        if(b[bi[j]]-c[bi[j]]<mibc)
                        {
                            mibc=b[bi[j]]-c[bi[j]];
                            mbc=j;
                        }
                    }
                    if(b[i]>=miba&&miba<=mibc){
                        ai[x]=bi[mba];
                        bi[mba]=i;
                        x++;
                        ans-=miba;
                        ans+=b[i];
                    }
                    else if(b[i]>=mibc&&miba>mibc){
                        ci[z]=bi[mbc];
                        bi[mbc]=i;
                        z++;
                        ans-=mibc;
                        ans+=b[i];
                    }
                    else
                    {
                        if(a[i]>=c[i]){
                            ai[x]=i;
                            x++;
                            ans+=a[i];
                        }
                        else {
                            ci[z]=i;
                            z++;
                            ans+=c[i];
                        }
                    }
                }
            }
            else if(c[i]>=b[i]&&a[i]<=c[i])
            {
                if(z<=n/2)
                {
                    ci[z]=i;
                    z++;
                    ans+=c[i];
                }
                else
                {
                    for(int j=1;j<z;j++){
                        if(c[ci[j]]-a[ci[j]]<mica)
                        {
                            mica=c[ci[j]]-a[ci[j]];
                            mca=j;
                        }
                        if(c[ci[j]]-b[ci[j]]<micb)
                        {
                            micb=c[ci[j]]-b[ci[j]];
                            mcb=j;
                        }
                    }
                    if(c[i]>=mica&&mica<=micb){
                        ai[x]=ci[mca];
                        ci[mca]=i;
                        x++;
                        ans-=mica;
                        ans+=c[i];
                    }
                    else if(c[i]>=micb&&mica>micb){
                        bi[z]=ci[mcb];
                        ci[mcb]=i;
                        y++;
                        ans-=micb;
                        ans+=c[i];
                    }
                    else
                    {
                        if(a[i]>=b[i]){
                            ai[x]=i;
                            x++;
                            ans+=a[i];
                        }
                        else{
                            bi[y]=i;
                            y++;
                            ans+=b[i];
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
