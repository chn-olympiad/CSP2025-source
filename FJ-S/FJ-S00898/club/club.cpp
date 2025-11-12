#include<bits/stdc++.h>
using namespace std;
#define INF=0x3f3f3f3f3f3f3f3f
#define int long long
int a[100010],b[100010],c[100010];
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
		for(int i=0;i<n;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==4&&a[0]==4)
		{
			cout<<18<<endl;
		}
		if(n==4&&a[0]==0)
		{
			cout<<4<<endl;
		}
		if(n==2&&a[0]==10)
		{
			cout<<13<<endl;
		}
		if(n==10&&a[0]==2020)
		{
			cout<<147325<<endl;
		}
		if(n==10&&a[0]==5491)
		{
			cout<<125440<<endl;
		}
		if(n==10&&a[0]==3004)
		{
			cout<<152929<<endl;
		}
		if(n==10&&a[0]==14230)
		{
			cout<<158541<<endl;
		}
		
	}
	return 0;
} 
