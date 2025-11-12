#include <bits/stdc++.h>
using namespace std;

int n;
long long sum;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out ","w",stdout);
	std::ios(0),cin.tie(0);
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