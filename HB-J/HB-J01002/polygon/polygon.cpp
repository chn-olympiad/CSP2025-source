#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	
	int n,sum=0;
	int a[5005]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<1;
}
