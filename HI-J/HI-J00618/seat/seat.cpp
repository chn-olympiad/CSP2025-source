#include<bits/stdc++.h>
using namespace std;
int a[10005]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+0,a+m*n+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i*j]==a[1])
			{
				cout<<n-1<<" "<<m;
			}
		}
	}
	return 0;
}

