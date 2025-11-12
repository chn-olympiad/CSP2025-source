#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	string a;
	int b[1001] = {},cnt = 0;
	cin >> a;
	for(int i = 0;i < a.size();i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			b[cnt] = a[i] - '0';
			cnt++;
		}
	}
	sort(b,b + cnt,cmp);
	for(int i = 0;i < cnt;i++)
	{
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}