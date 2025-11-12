#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000001];
int cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i];
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	return 0;
}
