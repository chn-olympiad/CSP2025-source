#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
char s[10000005];
int a[10000005],aa;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		int p=s[i];
		if(p<=57&&p>=48)
		{
			
			a[++aa]=p-48;
		}
	}
	sort(a+1,a+1+aa);
	for(int i=aa;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}