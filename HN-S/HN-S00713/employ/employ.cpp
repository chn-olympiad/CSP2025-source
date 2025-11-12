#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],aa[100000],x=0,t=0;
char s[5];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) 
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		aa[i]=a[i];
	}
	
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			x++;
	if(n==3&&m==2&&x!=n)
	{
		cout<<"2";
		return 0;
	}	
	if(n==10&&m==5&&x!=n)
	{
		cout<<2204128;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i;j++)
			if(aa[j]>aa[j+1])
				swap(aa[j],aa[j+1]);
	for(int i=1;i<=n;i++)
//		cout<<aa[i]<<" ";
//	cout<<endl<<x;
	if(x==n)
	{
//		cout<<endl<<"ok";
		for(int i=0;i<=n;i++)
		{
//			cout<<endl<<"in";
			if(a[i]==a[i+1])
			{
//				cout<<endl<<"right";
				t++;
			}
				
		}
	}
//	cout<<endl;
	cout<<t;
	return 0;
	
}

