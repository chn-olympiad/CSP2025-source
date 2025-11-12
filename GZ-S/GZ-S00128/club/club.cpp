//GZ-S00128¿×ÏôÒ¢ 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a[114514114514];
	cin>>t;
	for (int i=0;i<=t;i++)
	{
		int n; 
		cin>>n;
		for(int x=0;x<=n;x++)
		{
			cin>>a[x];
			if (a[x-1]<a[x])
			{
				a[x]=a[x-1];
			}
			cout<<a[x];
		}
	}
	
	
	return 0;
}
