#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
bool ff;
int t,n,a[N][5],ans,temp,s,tt[N],ttt;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		{
			s=0;
			cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[2][1]>>a[2][2]>>a[2][3];
			ttt=a[1][1]+a[2][2];
			s=max(s,ttt);
			ttt=a[1][1]+a[2][3];
			s=max(s,ttt);
			ttt=a[1][2]+a[2][1];
			s=max(s,ttt);
			ttt=a[1][2]+a[2][3];
			s=max(s,ttt);
			ttt=a[1][3]+a[2][2];
			s=max(s,ttt);
			ttt=a[1][3]+a[2][1];
			s=max(s,ttt);
			cout<<s<<"\n";
			continue;
		}
		s=0;
		ff=true;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			tt[i]=a[i][1];
			if(a[i][2]!=0) ff=false;
		}
		if(ff)
		{
			sort(tt+1,tt+1+n,cmp);
			for(int i=1;i<=(n/2);i++) s+=tt[i];
			cout<<s<<"\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				s=0;
				for(int j=1;j<=3;j++)
				{
					s+=a[i][j];
				}
				temp=s;
			}
		}
	}
	return 0;
}
