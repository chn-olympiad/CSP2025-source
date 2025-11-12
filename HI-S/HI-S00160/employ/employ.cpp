#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m;
	int u[100005];
	char s[100000];
	long long ans;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i];
	}
	ans=(n*n-m*m)%998244353;
	cout<<ans;
	return 0;
}

