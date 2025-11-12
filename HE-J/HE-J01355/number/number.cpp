#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
long long sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000005,'\n');
	for(int i=0;i<=1000005;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[sum]=(s[i]-48);
			sum++;
		}
		if((s[i]<48)||(s[i]>57&&s[i]<97)||(s[i]>122))
		{
			break;
		}
	}
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
