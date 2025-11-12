#include<bits/stdc++.h>
using namespace std;
int n,m,id;
int a[155];
void dfs(int i,int j,int num)
{
	if(a[num]==id)
	{
		cout<<j<<' '<<i;
		return;
	}
	if(j%2==1)
	{
		if(i>1)dfs(i-1,j,num+1);
		else dfs(i,j-1,num+1);
	}
	else
	{
		if(i<n)dfs(i+1,j,num+1);
		else dfs(i,j-1,num+1);
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	id=a[1];
	sort(a+1,a+n*m+1);
	if(m%2==1)dfs(n,m,1);
	else dfs(1,m,1);
	return 0;
}
