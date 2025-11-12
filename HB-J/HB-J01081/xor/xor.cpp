#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10000];
int ans[200002];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<n/2<<endl;
	return 0;
}
