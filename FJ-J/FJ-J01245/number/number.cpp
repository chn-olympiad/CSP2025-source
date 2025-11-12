#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	
	freopen("number.out","w",stdout);
	char st;
	int n;
	cin>>st;
	char nmu[10001];
		if(st>=48&&st<=57)
	{
		n++;
		nmu[n]+=st;
	}
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(nmu[i]>=nmu[j])
			{
				nmu[i]=nmu[i+1];
				
			}
			else
			nmu[j]=nmu[j+1];
		}
		cout<<nmu[i];
	}
	return 0; 
}
