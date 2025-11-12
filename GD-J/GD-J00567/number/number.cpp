#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
char ch;
string ans;
bool cmp(char a,char b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	while(cin >> ch)
	{
		if(ch>'9' || ch<'0')continue;
		ans+=ch;
	}
	sort(ans.begin(),ans.end(),cmp);
	cout << ans;
	return 0;
} 
