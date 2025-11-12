#include<bits/stdc++.h>
using namespace std;
int a[114514],b[114514]={0},c[114514]={0},d[114514]={0},s=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	
	while(t--)
	{
		s=0;
		cin>>n;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]&&a[i]>c[i])
			{
				d[i]=1;
				b[i]=0;
				c[i]=0;
				x++;
			}
			else if(b[i]>a[i]&&b[i]>c[i])
			{
				y++;
				d[i]=2;
				a[i]=0;
				c[i]=0;	
			}
			else if(c[i]>a[i]&&c[i]>b[i])
			{
				z++;
				d[i]=3;
				a[i]=0;
				b[i]=0;
			}
		}
		sort(a,a+n+1);
		sort(b,b+n+1);
		sort(c,c+n+1);
		for(int i=n;i>n/2;i--)
		{
			s+=a[i];
			s+=b[i];
			s+=c[i];
		}
		cout<<s<<endl;
	
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
