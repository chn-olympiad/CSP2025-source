#include <bits/stdc++.h> 
using namespace std;
char shu[1000005]; 
char ans[1000007];
int main() 
{ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=1000004,j=1;      
	cin>>shu;	
	for(int i=1;i<=n;i++)
	{
		for(int e=1;e<=9;e++)
		{
			if(shu[i]==e)
			{
				ans[j]=shu[i];
				j++;
			}
		}
	}
	sort(ans,ans+j+1);
	for(int a=j;a>=1;a--)
	{
		cout<<ans[a];
	}
	return 0;
} 
