#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,b,ans=0,s,t;
	cin>>n;
	int a[11000]={0};
	int h;
	cin>>h;
	for(int i=1;i<n;i++)
	{
		cin>>b;
		for(int j=1;j<=n;j++)
		{
			if(b>a[j])
			{
				for(int z=n-1;z>=j;z--)
				{
					a[z+1]=a[z];
				}
				a[j]=b;
				break;
			}
		}
		
	}
//	for(int j=1;j<=n*m;j++)
//		{
//			cout<<a[j]<<" ";
//		}
	for(int j=2;j<=n;j++)
		{
			t+=a[j];
			if(2*a[1]<t)
			ans++;
		}
//		cout<<endl<<ans<<endl;
	cout<<ans;
}
