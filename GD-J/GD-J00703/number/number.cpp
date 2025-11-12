#include <bits/stdc++.h>
typedef long long ll;
using  namespace std;
const int maxn = 1e6+10;
int a[maxn];
int tot;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	s = '=' + s;
	int n = s.length();
	for(int i=1;i<=n;i++)
	{
		char c = s[i];
		if('0'<= c && c<='9') a[++tot] = c-'0';
	}
	sort(a+1, a+1+tot, greater<int>());
	if(a[1]==0) cout<<0; 
	else for(int i=1;i<=tot;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
}
