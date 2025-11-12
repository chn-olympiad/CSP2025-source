#include<bits/stdc++.h>
using namespace std;
int a[100010];
int cnt=0;
int maxv=-1e9;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int nn=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) cnt++;
	}
	for(int i=1;i<=n;i+=2)
	{
		if(a[i]^a[i-1]==k) cnt++;
	}
	cout<<cnt;
	return 0;
}
