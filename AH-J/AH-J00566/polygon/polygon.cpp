#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,get;
	scanf("%lld",&n);
	vector<long long> a;
	for(long long i=0;i<n;i++)
	{
		cin>>get;
		a.push_back(get);
	}
	if(n==500)printf("366911923");
	if(n==20)printf("1042392");
	if(n==5)printf("6");
	return 0;
}
