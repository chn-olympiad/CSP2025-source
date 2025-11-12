#include<bits/stdc++.h>
using namespace std;
struct A
{
	int s1,s2,s3;
}a[200005];
bool aa(A a,A b)
{
	return a.s1>b.s1;
}
bool bb(A a,A b)
{
	return a.s2>b.s2;
}
bool cc(A a,A b)
{
	return a.s3>b.s3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T,n;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int ans=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].s1>>a[j].s2>>a[j].s3;
		}
		int sum1=0,sum2=0,sum3=0;
		if(n==2)
		{
			cout<<max(max(a[1].s1+a[2].s2,a[1].s2+a[2].s1),max(a[1].s3+a[2].s2,max(a[1].s2+a[2].s3,max(a[1].s1+a[2].s3,a[1].s3+a[2].s1))));
			continue;
		}
		sort(a+1,a+n+1,aa);
		for(int j=1;j<=n/2;j++)
		{
			sum1+=a[j].s1;
		}
		/*sort(a+1,a+n+1,bb);
		for(int j=1;j<=n/2;j++)
		{
			sum2+=a[j].s2;
		}
		sort(a+1,a+n+1,cc);
		for(int j=1;j<=n/2;j++)
		{
			sum3+=a[j].s3;
		}*/
		ans=max({sum1,sum2,sum3});
		cout<<ans<<endl;		
	}
}

