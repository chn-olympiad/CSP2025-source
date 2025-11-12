#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int a[1000005],l,cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	l=s.size();
	for (int i=0;i<l;i++) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,greater<int>());
	for (int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}

