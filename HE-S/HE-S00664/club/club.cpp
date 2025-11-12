#include <bits/stdc++.h>
using namespace std;
struct ma
{
	int  a1,a2,a3,cha;
} a[10010];
bool cmp1(ma q,ma w)
{
	return q.a1>w.a1;
}
bool cmp2(ma q,ma w)
{
	return q.a2>w.a2;
}
bool cmp3(ma q,ma w)
{
	return q.a3>w.a3;
}
bool cmpcha(ma q,ma w)
{
	return q.cha>w.cha;
}
int main()
{

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int t,n;
	cin>>t;
	while (t--)
	{
		int s1=0,s2=0,s3=0;
		int sa1=0,sa2=0,sa3=0;
		int ansd=0,ansc=0;
		cin>>n;
		for (int i=1; i<=n; i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int q=max(a[i].a1,max(a[i].a2,a[i].a3));
			int w=min(a[i].a1,min(a[i].a2,a[i].a3));
			int e=a[i].a1+a[i].a2+a[i].a3-q-w;
			a[i].cha=q-e;
			sa1+=a[i].a1;
			sa2+=a[i].a2;
			sa3+=a[i].a3;
		}
		
		if ((sa1>sa2)&&(sa1>sa3))
		{
			sort(a+1,a+n+1,cmp1);
		}
		else if ((sa2>sa1)&&(sa2>sa3))
		{
			sort(a+1,a+n+1,cmp2);
		}
		else 
		{
			sort(a+1,a+n+1,cmp3);
		}
		//1
		for (int i=1; i<=n; i++) 
		{
			if (s1<n/2)
			{
				if ((a[i].a1>a[i].a2)&&(a[i].a1>a[i].a3))
				{
					ansd+=a[i].a1;
					s1++;
					continue;
				}
			}
			if (s2<n/2)
			{
				if ((a[i].a2>a[i].a1)&&(a[i].a2>a[i].a3))
				{
					ansd+=a[i].a2;
					s2++;
					continue;
				}
			}
			if (s3<n/2)
			{
				if ((a[i].a3>a[i].a1)&&(a[i].a3>a[i].a2))
				{
					ansd+=a[i].a3;
					s3++;
				}
			}
		}
		//2
		int ans1=0;
		s1=0,s2=0,s3=0;
		for (int i=1; i<=n; i++) 
		{
			if (s1<n/2)
			{
				if ((a[i].a1>a[i].a2)||(a[i].a1>a[i].a3))
				{
					ans1+=a[i].a1;
					s1++;
					continue;
				}
			}
			if (s2<n/2)
			{
				if ((a[i].a2>a[i].a1)||(a[i].a2>a[i].a3))
				{
					ans1+=a[i].a2;
					s2++;
					continue;
				}
			}
			if (s3<n/2)
			{
				if ((a[i].a3>a[i].a1)||(a[i].a3>a[i].a2))
				{
					ans1+=a[i].a3;
					s3++;
				}
			}
		}
		ansd=max(ansd,ans1);
		//3
		s1=0,s2=0,s3=0;
		sort(a+1,a+n+1,cmpcha); 
		for (int i=1; i<=n; i++)
		{
			if (s1<n/2)
			{
				if ((a[i].a1>a[i].a2)&&(a[i].a1>a[i].a3))
				{
					ansc+=a[i].a1;
					s1++;
					continue;
				}
			}
			if (s2<n/2)
			{
				if ((a[i].a2>a[i].a1)&&(a[i].a2>a[i].a3))
				{
					ansc+=a[i].a2;
					s2++;
					continue;
				}
			}
			if (s3<n/2)
			{
				if ((a[i].a3>a[i].a1)&&(a[i].a3>a[i].a2))
				{
					ansc+=a[i].a3;
					s3++;
				}
			}
		}
		//4
		int ans2=0;
		s1=0,s2=0,s3=0;
		for (int i=1; i<=n; i++)
		{
			if (s1<n/2)
			{
				if ((a[i].a1>a[i].a2)||(a[i].a1>a[i].a3))
				{
					ans2+=a[i].a1;
					s1++;
					continue;
				}
			}
			if (s2<n/2)
			{
				if ((a[i].a2>a[i].a1)||(a[i].a2>a[i].a3))
				{
					ans2+=a[i].a2;
					s2++;
					continue;
				}
			}
			if (s3<n/2)
			{
				if ((a[i].a3>a[i].a1)||(a[i].a3>a[i].a2))
				{
					ans2+=a[i].a3;
					s3++;
				}
			}
		}

		ansc=max(ans2,ansc);
		int ans=max(ansd,ansc);
		cout<<ans<<"\n";
	}
	return 0;
}
