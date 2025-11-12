#include<bits/stdc++.h>
using namespace std;
int a[signed(1e2+10)],n,m,rnum,s[15][15];
void dfs(int i,int j,int cnt)
{
	s[i][j]=a[cnt];
	if(a[cnt]==rnum) {
		cout<<i<<" "<<j<<endl;
		return ;
	}
	if(i%2==1)
	{
		if(j==n) dfs(i+1,j,cnt+1);
		else dfs(i,j+1,cnt+1);
	}
	else
	{
		if(j==1) dfs(i+1,j,cnt+1);
		else dfs(i,j-1,cnt+1);
	}
 } 
 bool cmp(int a,int b)
 {
 	return a>b;
 }
signed main()
{
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		i==1 ? rnum=a[i]:rnum=rnum;
	}
	sort(a+1,a+n*m+1,cmp);
    dfs(1,1,1);
	return 0;
 } 
