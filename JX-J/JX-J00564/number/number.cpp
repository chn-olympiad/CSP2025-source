#include <bits/stdc++.h>
using namespace std;
string mm;
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<mm.size();i++)
	{
		if(mm[i]>='0'&&mm[i]<='9') 
			num[mm[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(num[i]>0)
		{
			for(int j=1;j<=num[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
