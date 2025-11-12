#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin >> a;vector<char> b;
	for(int i = 0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b.push_back(a[i]);
		}
	}
	sort(b.begin(),b.end(),cmp);
	for(int i = 0;i<b.size();i++)
	{
		cout << b[i];
	}
	return 0;
} 
