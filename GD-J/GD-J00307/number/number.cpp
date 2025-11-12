#include <bits/stdc++.h>
using namespace std;
string a;
long long b[10],ans=0,num=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<sizeof(a);i++)
	{
		  if(48<=a[i]&&a[i]<=57)
		  {
		  	 int ans=a[i]-48;
		  	 b[ans]+=1;
		  }
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i])
		{
			num=num*10+i;
			b[i]-=1;
		}
	}
	cout<<num;   
	return 0;
}
