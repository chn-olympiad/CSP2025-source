#include<bits/stdc++.h>

using namespace std;

string s;
int a[10000005],idx;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++)
	{
		if(isdigit(s[i]))
			a[++idx] = s[i]-48;
	}
	sort(a+1,a+idx+1,cmp);
	for(int i = 1;i <= idx;i++)
		cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
