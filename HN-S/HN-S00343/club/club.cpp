#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],ss,ss1;
struct abb{
	int xr,my;
}as[100005]; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]==b[i]&&b[i]==0)
				ss++;
			if(c[i]==0)
				ss1++;
		}
		if(ss==n)
		{
			ss=0;
			sort(a+1,a+n+1);
			for(int i=n/2;i>=1;i--)
			{
				ss+=a[i];
			}
			cout<<ss;
			continue;
		}
		if(ss1==n)
		{
			ss=0;
			ss1=0;
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			for(int i=n/2;i>=1;i--)
			{
				ss+=a[i];
			}	
			for(int i=n/2;i>=1;i--)
			{
				ss1+=b[i];
			}
			cout<<ss+ss1;
		}
		if(n==2)
		{
			ss=0;
			if(a[1]>max(b[1],c[1])&&a[1]>a[2])
				ss+=a[1];
			if(b[1]>max(a[1],c[1])&&b[1]>b[2])
				ss+=b[1];
			if(c[1]>max(b[1],a[1])&&c[1]>c[2])
				ss+=c[1];
			if(a[2]>max(b[2],c[2])&&a[2]>a[1])
				ss+=a[2];
			if(b[2]>max(a[2],c[2])&&b[2]>b[1])
				ss+=b[2];
			if(c[2]>max(b[2],a[2])&&c[2]>c[1])
				ss+=c[2];
		}
	}
	return 0;
} 
