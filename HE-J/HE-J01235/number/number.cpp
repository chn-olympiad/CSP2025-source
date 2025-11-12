#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+5;
string s;
int len,a[N],n;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(isdigit(s[i]))
		  a[++n]=s[i]-'0';
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	  cout<<a[i];
	return !(cout<<'\n');
}
