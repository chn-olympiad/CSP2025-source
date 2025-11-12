#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],k[101],b,c,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		k[i]=a[n*m-i+1];
	for(int i=1;i<=n*m;i++)
		if(b==a[i])c=i;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(k[i*n-n+j]==b)cout<<i<<" "<<j;
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(k[i*n-j+1]==b)cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
