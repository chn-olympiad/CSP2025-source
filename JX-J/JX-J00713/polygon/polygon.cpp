#include<bits/stdc++.h>
using namespace std;
long long oo=998244353;
long long a[10000001],n,m,k,l,p,r;
long long kp(int x)
{
	long long pp=x*(x-1)*(x-2),y;
	y=pp;
	y%=oo;
	for(int i=x-3;i>=1;i--){
		pp*=i;
		y+=pp;
		y%=oo;
	}
	return y;
}
void dfs(int x,int y,int z)
{
	if(z==n){if(z>=3&&2*y<x) p++;p%=oo;return ;}
	if(a[z]>y) dfs(x+a[z],a[z],z+1);
	else dfs(x+a[z],y,z+1);
	dfs(x,y,z+1);
	return ;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)m=1;
	}
	if(m==0) cout<<kp(n);
	else{
		dfs(0,0,1);
		cout<<p;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
