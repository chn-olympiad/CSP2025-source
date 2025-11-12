#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

char c;
int a[1000010];
long long ans;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0;
	while ( cin >> c )
		if ( c <= '9' && c >= '0' )
		{
			j++;
			a[j]=c-'0';
		}
	sort(a+1,a+j+1,cmp);
	for ( int i=1;i<=j;i++ )
		ans=ans*10+a[i];
	cout << ans;
	return 0;
}
