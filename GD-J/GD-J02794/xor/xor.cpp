#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long k;
int a[500010],s,d;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);	
cin>>n>>k;
bool flag=false;
for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	if(a[i]=1&&flag==false)
		s++;
	else if(a[i]=0&&flag==false)	
		d++;
	else
		flag=true;		
	}
if(s==n)
	{
	cout<<n/2;
	return 0;	
	}
if(d==n)
	{
	cout<<n;
	return 0;	
	}
if(s+d==n)
	{
	if(k==0)
		{
		cout<<d+s/2;
		return 0;	
		}	
	else if(k==1)
		{
		cout<<s;
		return 0;	
		}	
	}
return 0;				
}
