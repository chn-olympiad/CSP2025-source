#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	int t = 0;
	for(int i=0; i<len; i++)
		if(isdigit(s[i]))
			a[t++] = s[i]-'0';
	sort(a,a+t);
	for(int i=t-1; i>=0; i--)
		cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
