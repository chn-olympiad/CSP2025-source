#include<bits/stdc++.h>
#define int long long
#define N 20
using namespace std;

string s;
array<int,N> a;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	a.fill(0);
	
	for(const auto &e:s)
	if(e>='0' && e<='9')
	a.at(e-'0')++;
	
	for(int i=9;i>=0;i--)
	for(int j=1;j<=a.at(i);j++)
	printf("%lld",i);
	return 0;
}
