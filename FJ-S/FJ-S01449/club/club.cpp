#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
struct maiyi
{
	int m1,m2,m3;
	int he;
}m[100010];
bool cmp1(maiyi x,maiyi y)
{
	return x.he>y.he;
}
bool cmp2(maiyi x,maiyi y)
{
	return x.he<y.he;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int re=n/2;
		
		int ans;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].m1>>m[i].m2>>m[i].m3;
			m[i].he=m[i].m1+m[i].m2+m[i].m3;
		}
		if(n==2)
		{
			ans=m[1].m1+m[2].m2;
			ans=max(m[1].m1+m[2].m3,ans);
			ans=max(m[1].m2+m[2].m1,ans);
			ans=max(m[1].m2+m[2].m3,ans);
			ans=max(m[1].m3+m[2].m2,ans);
			ans=max(m[1].m3+m[2].m1,ans);
		}
		else
		{
			sort(m+1,m+1+n,cmp1);
			int s1=0,s1r=0;
			int s2=0,s2r=0;
			int s3=0,s3r=0;
			for(int i=1;i<=n;i++)
			{
				int mai=max(m[i].m1,m[i].m2);
				mai=max(mai,m[i].m3);
				if(m[i].m1>=m[i].m2 && m[i].m1>=m[i].m3 && s1r<re)
				{
					s1+=mai;
					s1r++;
				}
				else if(m[i].m2>=m[i].m1 && m[i].m2>=m[i].m3 && s2r<re)
				{
					s2+=mai;
					s2r++;
				}
				else if(m[i].m3>=m[i].m2 && m[i].m3>=m[i].m1 && s3r<re)
				{
					s3+=mai;
					s3r++;
				}
			}
			 ans=s1+s2+s3;
			sort(m+1,m+1+n,cmp2);
			s1=0,s1r=0;
			s2=0,s2r=0;
			s3=0,s3r=0;
			for(int i=1;i<=n;i++)
			{
				int mai=max(m[i].m1,m[i].m2);
				mai=max(mai,m[i].m3);
				if(m[i].m1>=m[i].m2 && m[i].m1>=m[i].m3 && s1r<re)
				{
					s1+=mai;
					s1r++;
				}
				else if(m[i].m2>=m[i].m1 && m[i].m2>=m[i].m3 && s2r<re)
				{
					s2+=mai;
					s2r++;
				}
				else if(m[i].m3>=m[i].m2 && m[i].m3>=m[i].m1 && s3r<re)
				{
					s3+=mai;
					s3r++;
				}
			}
			ans=max(ans,s1+s2+s3);
		}
		cout<<ans<<endl;
	}
	return 0;
}
