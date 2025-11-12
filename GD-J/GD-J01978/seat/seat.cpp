#include<bits/stdc++.h>
using namespace std;
int s[101],n,m;
int se[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	int score=s[1];
	sort(s+1,s+n*m+1,greater<int>());
	int pos=1,cnt=0;
	while(s[pos]!=score)pos++;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(j%2==1){
				se[i][j]=s[++cnt];
			}
			else{
				se[n-i+1][j]=s[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(se[i][j]==score){
				cout<<j<<' '<<i;
				return 0;
			}	
		} 
	}
	return 0;
}
