#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	long long ans=1;
	for(int i=n-m+1;i<=n;i++) ans=ans*i%998244353;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rnd;
	cout<<rnd(gen,uniform_int_distribution<int>::param_type(0,ans));
	return 0;
}
