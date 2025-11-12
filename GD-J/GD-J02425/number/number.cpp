#include<bits/stdc++.h>
using namespace std;
string s;
vector <int> a;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char c : s)
	{
		if('0'<=c&&c<='9')a.push_back(c-'0');
	}
	sort(a.begin(),a.end(),cmp);
	for(int i : a)cout << i;
	return 0;
} 
