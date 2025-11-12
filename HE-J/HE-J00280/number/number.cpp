#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000096;
char s[N];
int a[N],j;
string h;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s+1;
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[++j]=s[i]-'0'+1;
		}
	}
	sort(a+1,a+j+1,cmp);
	for (int i=1;i<=j;i++)
	{
		h+=a[i]+'0'-1;
	}
	cout << h;
	return 0;
}
