#include<bits/stdc++.h>
using namespace std;
long long a[10000],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	if(ans>=a[n-1]*2) cout<<"1";
	else cout<<"0";
	return 0;
}
