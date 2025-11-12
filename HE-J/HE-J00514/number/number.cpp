#include <bits/stdc++.h>

using namespace std;
long long a[10],k=1;
long long ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string num;
	cin>>num;
	for(int i=0;i<num.size();i++)
	{
		int _a=(int)num[i]-'0';
		if(_a<=9 && _a>=0)
		{
			a[_a]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			if(i==0)
			{
				ans=ans*10;	
				a[i]--;
				continue;
			}
			ans=ans*10+i;
			a[i]--;
			k=k*10;
		}	
	}
	cout<<ans;
	return 0;
 } 
 
