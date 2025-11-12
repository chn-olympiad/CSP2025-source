#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.cpp","r",stdin);
	freopen("number.cpp","w",stdout);
	char s[10001];
	cin>>s;
	int i=0,sum=0,sl=strlen(s),n=sl;
	long int a[100001];
	while(sl)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[sum]=s[i]-48;
			sum+=1;
		}
		i++;
		sl--;
	}
	sort(a,a+sum);
	for(int j=sum-1;j>=0;j--)
	{
		cout<<a[j];
	}
	return 0;
} 
