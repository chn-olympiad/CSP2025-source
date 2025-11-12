#include<bits/stdc++.h>
#define int long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string s;
vector<int> a;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s)if('0'<=i&&i<='9')a.push_back(i-'0');
	sort(a.begin(),a.end(),[](int x,int y){return x>y;});
	for(auto i:a)printf("%lld",i);
	return 0;
}
