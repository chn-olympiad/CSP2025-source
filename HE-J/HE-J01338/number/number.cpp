#include<bits/stdc++.h>
using namespace std;
char a[1000000000];
long long m[100000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n;
	char a[n];
	for(int i=0;i<n;i++)
	{
		cin >>a[i];
		for(int j=0;j<=n;j++)
		{
			if(a[i]='0')
			{
				m[j]+=a[i];
			}
			if(a[i]='1')
			{
				m[j]+=a[i];
			}
			if(a[i]='2')
			{
				m[j]+=a[i];
			}
			if(a[i]='3')
			{
				m[j]+=a[i];
			}
			if(a[i]='4')
			{
				m[j]+=a[i];
			}
			if(a[i]='5')
			{
				m[j]+=a[i];
			}
			if(a[i]='6')
			{
				m[j]+=a[i];
			}
			if(a[i]='7')
			{
				m[j]+=a[i];
			}
			if(a[i]='8')
			{
				m[j]+=a[i];
			}
			if(a[i]='9')
			{
				m[j]+=a[i];
			}
			if(m[j]<m[j+1])
			{
				m[j]=m[j+2];
				m[j+1]=m[j];
				m[j+2]=m[j];
			} 
			cout <<m[j];
		}
	}
	return 0;
}
