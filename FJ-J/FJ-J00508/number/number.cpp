#include<bits/stdc++.h> 
using namespace std;
char a[100002];
long long int b[100002],c[100002];
int main()
{
	long long int ans=0,p=0,d;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<100001;i++)a[i]='q';
	cin>>a;
	for(int i=0;i<100001;i++)
	{
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
		{
			d=a[i]-48;
			b[d]+=1;
		}
	}
	for(int i=0;i<=9;i++)
	{
		long long int x=b[i];
		for(int j=0;j<x;j++)
		{
			ans+=i*pow(10,p);
			p+=1;
		}
	}
	cout<<ans;
	return 0;
}
