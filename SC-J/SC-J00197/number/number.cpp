#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
string str;
vector<int> num;
bool cmp(int x,int y)
{
	return x > y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0' && str[i] <= '9')
			num.push_back(str[i]-'0');
	sort(num.begin(),num.end(),cmp);
	for(int x:num) cout<<x;
	return 0;
}