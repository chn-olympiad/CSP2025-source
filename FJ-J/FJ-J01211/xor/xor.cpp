#include<bits/stdc++.h>
using namespace std;
int a[100010];
int zh(int x,int y)
{
	int z[1000],s[1000],h[1010],i=1,j=1;
	if(x==0) z[1]=0;
	if(y==0) s[1]=0;
	while(x!=0)
	{
		z[i]=x%2;
		i++;
		x/=2;
	}
	while(y!=0)
	{
		z[j]=y%2;
		j++;
		x/=2;
	}
	i--,j--;
}
int main(){
	int n,k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0) cout<<0;
	return 0;
}
