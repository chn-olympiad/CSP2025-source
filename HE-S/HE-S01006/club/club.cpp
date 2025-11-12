#include<bits/stdc++.h>
using namespace std;
long long t,m;
long long n;
long long a[500050],b[500050],c[500050]; 

long long ans=0;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		
		long long aa=0,bb=0,cc=0; 
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			long long maxx=0;
			cin>>a[i]>>b[i]>>c[i];
			//aa[i]=a[i];
			//bb[i]=b[i];
			//cc[i]=c[i];
			maxx=max(a[i],max(b[i],c[i]));
			if(maxx==a[i])
			{
				aa++;
				if(aa>m)
				{
					aa--;
					if(b[i]>=c[i])
					{
						maxx=b[i];
					}
					else if(c[i]>=b[i])
					{
						maxx=c[i];
					}
				}
				//cout<<"maxx是"<<maxx<<endl; 
				//怎么把全部中的最大换为第二 
			}
			else if(maxx==b[i])
			{
				bb++;
				if(bb>m)
				{
					bb--;
					if(a[i]>=c[i])
					{
						maxx=a[i];
					}
					else if(c[i]>=a[i])
					{
						maxx=c[i];
					}
				}
				//cout<<"maxx是"<<maxx<<endl;
			}
			else if(maxx==c[i])
			{
				cc++;
				if(cc>m)
				{
					cc--;
					if(b[i]>=a[i])
					{
						maxx=b[i];
					}
					else if(a[i]>=b[i])
					{
						maxx=a[i];
					}
				}
				//cout<<"maxx是"<<maxx<<endl;
			}
			ans+=maxx;
			//cout<<"是这个"<<aa<<" "<<bb<<" "<<cc<<endl;
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
