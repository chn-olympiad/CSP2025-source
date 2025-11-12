#include<bits/stdc++.h>
using namespace std;
char s[1000001],a[10];
long long j,n,m;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while(s[j])
	{
		if(s[j]>='0' && s[j]<='9') a[n]=s[j];
		n++;
		j++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]<a[j+1])
			{
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
	}
	for(int i=0;i<n;i++) cout<<a[i];
	return 0;
}
