#include<bits/stdc++.h>
#define int long long
#define unint unsigned long long 
using namespace std;
const int N=1e6+50;

string s;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::with_sync_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	std::cin>>s;
	sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]>='0'&&s[i]<='9') printf("%c",s[i]);
	return 0;
}
