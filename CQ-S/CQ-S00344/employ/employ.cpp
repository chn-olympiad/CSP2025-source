#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","W",stdout);
	int a[100000],s=0;
	int b;
	cin>>n>>m;
		cin>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sort(a,a+n+1);
		s+=a[i];
	}
	cout<<s-1;
	return 0;
}
