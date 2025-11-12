#include <bits/stdc++.h>
using namespace std;
int a[10000],n;
long long s=0;
void solve(int num,int l,int m,int u,bool f){
	if(num>=3&&l>m*2&&f)
		s++;
	if(u<n){
		solve(num,l,m,u+1,0);
		solve(num+1,l+a[u],max(m,a[u]),u+1,1);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	solve(0,0,0,0,1);
	cout<<s%998244353;
	return 0;
}
