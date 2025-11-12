#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1),reverse(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
