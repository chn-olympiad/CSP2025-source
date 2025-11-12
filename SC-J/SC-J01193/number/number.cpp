#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,a[N],num;
string s; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')a[++num]=s[i]-'0';
	sort(a+1,a+1+num,greater<int>());
	for(int i=1;i<=num;i++)cout<<a[i];
	return 0;
 } 