#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s;
void dfs(int l,int r,int xz,long long lj,int g){
	if(lj>xz&&g>=2)
	{
		s+=r-l+2;
		s%=998244353;
		return ;
	}
	for(int i=l;i<=r;i++)
	{
		dfs(i+1,r,xz,lj+a[i],g+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		dfs(1,i-1,a[i],0,0);
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
