#include<bits/stdc++.h>
#define int long long
using namespace std;
const int BIG=2e6;
string s;
int a[BIG],k;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[++k]=s[i]-'0';
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)cout<<a[i];
	return 0;
}
