#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n=s.size();
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<(int)a.size();i++)
	{
		cout << a[i];
	}
	return 0;
}

