#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[2000005],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++tot]=s[i]-'0';
		}
	}
	stable_sort(a+1,a+tot+1);
	if(a[tot]==0)
	{
		printf("0");
		return 0;
	}
//	puts("");
	for(int i=tot;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
