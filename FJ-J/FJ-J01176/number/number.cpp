#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c=0;
	char b[100001];
	int n=s.size();
	char a[n];
	for(int i=0;i<n;i++)
	{
	    a[i]=s[i];
		if(a[i]>='0'&&a[i]<='9')
		{
			b[c]=a[i];
			c++;
		}
		else
		{
			continue;
		}
	}
	for(int i=0;i<c;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if(b[i]<b[j])
			{
				int temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	for(int i=0;i<c;i++)
	{
		cout<<b[i];
	}
	return 0;
 } 
