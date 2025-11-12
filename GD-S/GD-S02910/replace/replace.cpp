#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string x[200005],y[200005],s;
int main() 
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=m;i++)
	{
		cnt=0;
		cin>>s;
		int len=s.size();
		for(int l=0;l<len;l++) 
		{
			for(int r=l+1;r<len;r++) 
			{
				for(int k=l;k<=r;k++) 
				{
					
				}
			}
		}
	}
	return 0;
} 
