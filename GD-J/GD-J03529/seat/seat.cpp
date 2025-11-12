#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1000005],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
		if(s[i]>s[1])
		ans++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i&1==1)
		{
			for(int j=1;j<=n;j++)
			{
				if((i-1)*n+j==ans+1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=i*n;j>=(i-1)*n+1;j--)
			{
				if(ans+1==j)
				{
					cout<<i<<" "<<i*n-j+1;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
