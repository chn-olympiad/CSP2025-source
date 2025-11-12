#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> q;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++)
		if (s[i] >= '0' && s[i] <= '9')
		    q.push_back(s[i] - '0');
	sort(q.begin(),q.end(),cmp);
	for (int i = 0;i < q.size();i++)
	    cout << q[i];
} 
