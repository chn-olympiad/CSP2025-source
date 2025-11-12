#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	char s;
	int n,q,m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=m;j++)
		{
			
			if(s[i]==0&&s[j]==0)
			{
				cout<<"+"<<s[i]; 
			}	
		}
		
	}
	
	return 0;
}

