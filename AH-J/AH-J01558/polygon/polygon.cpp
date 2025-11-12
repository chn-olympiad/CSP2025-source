#include <bits/stdc++.h>
const int N=5010;
const int mod=998244353;
int n;
int a[N];
using namespace std;
int power(int a,int b){
	if(b==1) return a;
	return a*power(a,b-1)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=1;
	for(int i=1;i<=n-3;i++){
		ans+=power(n,i);
	}
	cout<<ans;
	return 0;
}

