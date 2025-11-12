#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,asum,bsum,csum,like,res;
int a[MAXN],b[MAXN],c[MAXN],f[MAXN];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
		for(int i=1;i<=n;i++) f[i]=0;
		like=0,res=0,asum=0,bsum=0,csum=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        f[0]=-1;
        for(int i=1;i<=n;i++)
        {
            if(max(a[i],max(b[i],c[i]))==a[i])
            {
                asum++;
                like+=a[i];
            }
            else if(max(a[i],max(b[i],c[i]))==b[i])
            {
                bsum++;
                like+=b[i];
            }
            else if(max(a[i],max(b[i],c[i]))==c[i])
            {
                csum++;
                like+=c[i];
            }
    }
    if(asum<=n/2 && bsum<=n/2 && csum<=n/2) cout<<like<<"\n";
    else
    {
        res=max(asum,max(bsum,csum))-n/2;
        for(int i=1;i<=n;i++)
        {
            f[i]=max(a[i],max(b[i],c[i]))-(a[i]+b[i]+c[i]-max(a[i],max(b[i],c[i]))-min(a[i],min(b[i],c[i])));
				for(j=1;j<=i;j++)
				{
					if(f[j]>f[i]) swap(f[i],f[j]);
					else continue;
				}
        }
        for(int i=1;i<=res;i++) like-=f[i];
        cout<<like<<"\n";
    }
    }
   return 0;
}
