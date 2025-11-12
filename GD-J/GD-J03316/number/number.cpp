#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ccmp(int a,int b)
{
	return a > b;
}
int a[1000001];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),m=0;
	for (int i=0;i<n;i++)
		{
		if (s[i]>='0'&&s[i]<='9')
			{
			m++;
			a[m]=s[i]-'0';
			}
		}
	sort(a+1,a+1+m,ccmp);
	if (a[1]==0)m=1;
	for (int i=1;i<=m;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
