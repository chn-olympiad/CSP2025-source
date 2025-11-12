#include<bits/stdc++.h>
using namespace std;
long long b[3000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int n;
	cin >>a;
	n=a.size();
	a=' '+a;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<'a')
		{
			b[++m]=a[i]-'0';
		}
	} 
	sort(b+1,b+m+1);
	for(int i=m;i>=1;i--)
	{
		printf("%lld",b[i]);
	}
	return 0;
}

