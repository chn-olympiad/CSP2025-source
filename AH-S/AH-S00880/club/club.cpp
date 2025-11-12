#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[100010][4]={0},b[100010]={0},c[100010]={0};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		long long ans=0;
		cin>>n;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxa=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=maxa;
			if(maxa==a[i][1])b[i]=1,y++;
			else if(maxa==a[i][2])b[i]=2,z++;
			else b[i]=0,x++;
		}
		int m=0,k=0;
		if(x>n/2)
		{
			m=x-n/2;
			k=x;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==0)
					c[x--]=abs(a[i][0]-max(a[i][1],a[i][2]));
			}
		}
		else if(y>n/2)
		{
			m=y-n/2;
			k=y;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==1)
					c[y--]=abs(a[i][1]-max(a[i][0],a[i][2]));
			}
		}
		else if(z>n/2)
		{
			m=z-n/2;
			k=z;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==2)
					c[z--]=abs(a[i][2]-max(a[i][1],a[i][0]));
			}
		}
		sort(c+1,c+k+1);
		for(int i=1;i<=m;i++)
		{
			ans-=c[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
