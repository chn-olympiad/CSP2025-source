#include<bits/stdc++.h>
using namespace std;
int a[155];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	 a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	 for(int j=1;j<=a[i];j++)
	  cout<<i;
	return 0;
}
