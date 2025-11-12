#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string a;
int b[1000001],cnt;
int main()
{
	freopen(" number.in","r",stdin);
	freopen(" number.out","w",stdout);
	
	cin>>a;
	for(int i=0;i<=a.size();i++)
	{
		if(a[i]<='9' && a[i]>='0')
		{
			b[cnt]=a[i]-'0';
			cnt++;
		}
	}
	
	int max=0;
	for(int i=0;i<cnt;i++)
	{
		max=0;
		for(int j=0;j<=cnt;j++)
		{
			if(b[max]<=b[j])
			{
				max=j;
			}	
		}
		cout<<b[max];
		b[max]=-1;
	}
	return 0;
}  
