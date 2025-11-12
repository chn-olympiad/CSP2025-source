#include<bits/stdc++.h>
using namespace std;
long long  s[1001];
long long k[1001][1001];
bool judge(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];	
	}
	int y=s[1];	
	sort(s+1,s+1+n*m,judge);
	long long cnt=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				k[j][i]=s[cnt];
				cnt++;
			}		
		}
		else 
		{
			for(int j=n;j>=1;j--){
				k[j][i]=s[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(k[i][j]==y)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
