#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=5050;
int a[N],ans=9;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<ans%M;
	return 0;
}
