//GZ-S00421 毕节七星关东辰实验学校 赵云霄
#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[100005],b[100005],c[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		long long x,y,z;
		long cnta=1,cntb=1,cntc=1;
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(max(x,max(y,z))==x)
			{
				a[cnta]=x;
				cnta++;
			}
			if(max(x,max(y,z))==y)
			{
				b[cntb]=y;
				cntb++;
			}
			if(max(x,max(y,z))==z)
			{
				c[cntc]=z;
				cntc++;
			}
		}
		sort(a+1,a+1+cnta,cmp);
		sort(b+1,b+1+cntb,cmp);
		sort(c+1,c+1+cntc,cmp);
		for(int i=1;i<=n/3;i++)
		{
			ans+=a[i];
			ans+=b[i];
			ans+=c[i];
		}
		cnta=n/3+1,cntb=n/3+1,cntc=n/3+1;
		for(int i=n/3+1;i<=n/2;i++)
		{
			if(max(a[cnta],max(b[cntb],c[cntc]))==a[cnta])
			{
				ans+=a[cnta];
				cnta++;
			}
			if(max(a[cnta],max(b[cntb],c[cntc]))==b[cntb])
			{
				ans+=b[cntb];
				cntb++;
			}
			if(max(a[cnta],max(b[cntb],c[cntc]))==c[cntc])
			{
				ans+=c[cntc];
				cntc++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
