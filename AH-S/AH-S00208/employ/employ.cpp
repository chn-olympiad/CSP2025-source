#include<bits/stdc++.h>
using namespace std;
long long jie(int n){
	if(n==1)return 1;
	return (n*jie(n-1))%998244353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,t;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)cin>>t;
	cout<<jie(n);
	return 0;
}
