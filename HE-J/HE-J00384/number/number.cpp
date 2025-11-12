#include<bits/stdc++.h>
using namespace std;
int p,a[1000005];
string s,ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++p]=s[i]-'0';
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++)
		ans+=a[i]+'0';
	cout << ans;
	return 0;
}
