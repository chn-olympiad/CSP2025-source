#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int mx,n,a[N],x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n=s.length();
	for (int i=0;i<n;i++)
	{
		if ('0'<=s[i]&&s[i]<='9')
		{
			x+=1;
			a[x]=(int)s[i]-48;
		}
	}
	sort(a+1,a+x+1);
	for (int i=x;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}