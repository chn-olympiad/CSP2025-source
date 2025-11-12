#include<bits/stdc++.h>
using namespace std;
//C:\Users\user\Downloads\cspj
int n,maxn;
int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3)
	{
		cout<<0<<endl;
		return 0;
	}
	else
	{
		cout<<1;
		return 0;
	}
	return 0;
}