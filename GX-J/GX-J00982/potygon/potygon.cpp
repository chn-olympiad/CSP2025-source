#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	freopen("potygon.in","r",stdin);
	freopen("potygon.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++)
	{
	  cin>>a[i];
	  cout<<a[i];
    }
	return 0;
}

