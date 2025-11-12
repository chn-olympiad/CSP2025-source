#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1; i<=2; i++)
	{
		cin>>a[i];
	}
	if(a[1]==a[2])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
