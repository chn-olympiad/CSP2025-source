#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int c[1000001],tot;
bool Chara(int x,int y)
{
	return x>y;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9') c[++tot]=s[i]-'0';
	}
	sort(c+1,c+tot+1,Chara);
	for(int i=1;i<=tot;i++) cout<<c[i];
	return 0;
}