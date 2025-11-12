#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,a[505],sum;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=(a[i]>0);
	if(sum<m)cout<<0;
	else
	{
		int mul=1;
		for(int i=1;i<=sum;i++)mul=mul*i%M;
		cout<<mul; 
	}
	return 0;
}

