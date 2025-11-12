#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,aa[100010],ab[100010],ac[100010],la,lb,lc;
int n,a[4],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(aa,0,sizeof(aa));la=0;
		memset(ab,0,sizeof(ab));lb=0;
		memset(ac,0,sizeof(ac));lc=0;
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
			if(a[1]>=a[2] and a[1]>=a[3])
			{
				ans+=a[1];
				la++;
				aa[la]=max(a[2],a[3])-a[1];
			}
			if(a[2]>a[1] and a[2]>=a[3])
			{
				ans+=a[2];
				lb++;
				ab[lb]=max(a[1],a[3])-a[2];
			}
			if(a[3]>a[2] and a[3]>a[1])
			{
				ans+=a[3];
				lc++;
				ac[lc]=max(a[2],a[1])-a[3];
			}
		}
		sort(aa+1,aa+1+la);
		sort(ab+1,ab+1+lb);
		sort(ac+1,ac+1+lc);
		n=n>>1;
		for(int i=n+1;i<=la;i++) ans+=aa[i];
		for(int i=n+1;i<=lb;i++) ans+=ab[i];
		for(int i=n+1;i<=lc;i++) ans+=ac[i];
		cout<<ans<<endl;
	}
	return 0;
}
