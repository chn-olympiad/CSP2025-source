#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100];
	cin>>s;
	char a[100];
	int n=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[i]=s[i];
			n++;
		}
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(a[j]<a[j+1])
		{
			char f=a[j];
				 a[j]=a[j+1];
				 a[j+1]=f;
		} 
	}
	for(int i=0;i<n;i++)
	cout<<a[i];
	return 0;
} 