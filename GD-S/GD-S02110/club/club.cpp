#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],s[100005],c1,c2,c3,sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		sum=c[1]=c[2]=c[3]=0;
		cin>>n;
		for(long long i=0;i<n;i++)
		{
			cin>>a[i].fi>>a[i].se>>a[i].th;
			sum+=max(a[i].fi,max(a[i].se,a[i].th)),ma=0;
			if(a[i].fi>ma) ma=a[i].fi,maw=1;
			if(a[i].se>ma) ma=a[i].se,maw=2;
			if(a[i].th>ma) ma=a[i].th,maw=3;
			c[maw]++,a[i].s=maw;
		}
		if(c[1]>c[2]&&c[1]>c[3])
		{
			sort(a,a+n,cmp1);
			for(long long i=0;i<n;i++)
			{
				if(c[1]<=n/2) break;
				if(a[i].s==1)
				{
					c[1]--,sum-=a[i].fi;
					if(a[i].se>=a[i].th) sum+=a[i].se;
					else sum+=a[i].th;
				}
			}
		}
		if(c[2]>c[1]&&c[2]>c[3])
		{
			sort(a,a+n,cmp2);
			for(long long i=0;i<n;i++)
			{
				if(c[2]<=n/2) break;
				if(a[i].s==2)
				{
					c[2]--,sum-=a[i].se;
					if(a[i].fi>=a[i].th) sum+=a[i].fi;
					else sum+=a[i].th;
				}
			}
		}
		if(c[3]>c[1]&&c[3]>c[2])
		{
			sort(a,a+n,cmp3);
			for(long long i=0;i<n;i++)
			{
				if(c[3]<=n/2) break;
				if(a[i].s==3)
				{
					c[3]--,sum-=a[i].th;
					if(a[i].fi>=a[i].se) sum+=a[i].fi;
					else sum+=a[i].se;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//16:13 T1做完，样例全A，预计橙
//好的S组全炸了，预计116分 
/*-----------------题外话-------------
什么？你说我为什么T1做了2h？
因为一个唐人错误（不是feropen,froepen,fropen,feopen等等)导致死活调不对
qwq 
*/ 
