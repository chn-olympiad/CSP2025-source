#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=0;j<a[i];j++)
			cout<<i;
	cout<<endl;
	return 0;
}
