#include <bits/stdc++.h>
using namespace std;
int n,m,sum1=0,sum2=0,a[100005],b[100005],j=1;
string str;
bool flag[100005];
int main()
{
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		flag[i]=true;
		if(str[i]=='0')
		{
			sum2++;
			b[j]=i;
			j++;
		}
	}
	for(int i=1;i<=j;i++)
	{
		if(a[i]<=sum2&&flag[a[i]]!=false)
		{
			sum1-=(n-b[i]-1)*n*2;
			flag[a[i]]=false;
		}
	}
	sum1+=n*n;
	cout<<sum1-1;
	return 0;
}
