#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	int a[n],sum = 0;
	memset(a,-1,sizeof(a));
	for(int i = 0; i < n; i++)
	{
		if(s[i] >= '0' and s[i] <= '9')
		{
			a[i] = (int)(s[i] - '0');
			sum++;
		}
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < sum; i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
