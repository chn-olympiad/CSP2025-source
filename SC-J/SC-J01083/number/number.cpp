#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int q[1000010],l=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=strlen(a);
	for(int i=0;i<n;i++)
	{
		if('0'<=a[i]&&'9'>=a[i])
		{
			l++;
			q[l]=a[i]-'0';
		}
	}
	sort(q+1,q+l+1);
	for(int i=l;i>0;i--)
	{
		printf("%d",q[i]);
	}
	return 0;
}