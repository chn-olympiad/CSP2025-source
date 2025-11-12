#include<bits/stdc++.h>
using namespace std;
int a[100005]={0},n=0,m=0,x=0,ans=0;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+x+1);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[x]==ans)
			{
				if(i%2==1)cout<<i<<" "<<j;
				if(i%2==0)cout<<i<<" "<<n-j+1;
			}
			x--;
		}
	}
	return 0;
}
