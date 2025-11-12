#include<bits/stdc++.h>
using namespace std;
int a[1000000+100];
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string  s;
	cin>>s;
	int j=0; 
	for(int i=0; i<=s.length()-1; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i];
			j++;
		}
	}
	for(int i=0; i<=j-1; i++)
	{
		a[i]=a[i]-48;
	}
	sort(a,a+j);
	int sum=0;
	for(int i=j-1; i>=0; i--)
	{
		sum=sum*10+a[i];
	}
	cout<<sum<<endl;
	return 0;
}
