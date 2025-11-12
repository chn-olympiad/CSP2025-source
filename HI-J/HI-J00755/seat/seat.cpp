#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int n,m;
cin>>n>>m;
int s[n*m],a[n][m];
a[0][0]=s[0];
for(int i=0;i<n*m;i++)
{
	cin>>s[i];
}
for(int j=0;j<n;j++)
{
	for(int i=0;i<m;i++)
	{
		if(s[i]>s[0]){
			if(j%2!=0)
			{
				a[i+1][j]=s[0];
			}
			else a[i-1][j]=s[0];
		}
		
	}
}
for(int i=n;i>0;i--)
{
	for(int j=m;j>0;j--)
	{
		if(a[i][j]==s[0])
		{
			cout<<j<<" "<<i;
			break;
		}
	}
}

 return 0;
}


