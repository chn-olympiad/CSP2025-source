#include <bits/stdc++.h>
using namespace std;
long long a[10000];
const int maxn=998244353;
long long c[10000]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,m;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	c[1]=2;
	for(long long i=2;i<=n;i++){
		c[i]=c[i-1]*2%maxn;
	}
	cout<<(c[n]+maxn-n-(n*(n-1))%maxn)%maxn;
	return 0;
}  
