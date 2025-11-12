#include <bits/stdc++.h>
using namespace std;


int n;
long long sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out ","w",stdout);
	ios::sycn_with.stdio(0),cin.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		long long x;
		cin>>x;
		sum = sum + x;
	}
	int ans = sum;
	cout<<ans<<endl;
}