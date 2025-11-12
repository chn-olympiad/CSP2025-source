#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);
	int n,m,a[10001];
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i*j];
		}
	}
	int s=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i*j]>a[1]) s++;
		}
	}
	if(s<n) cout<<s<<" 1"<<endl;
	else if(s<2*n) cout<<2*n-s<<" 2"<<endl;
	else if(s<3*n) cout<<s-2*n<<" 2"<<endl;
	else if(s<4*n) cout<<4*n-s<<" 2"<<endl;
} 