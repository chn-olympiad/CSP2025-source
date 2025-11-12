#include<bits/stdc++.h>
using namespace std;
const int maxn=998244353;
long long a[100005],g[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,m;
	g[1]=2;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++) g[i]=g[i-1]*2%maxn;		
	cout<<(g[n]+maxn-n-n*(n-1)%maxn)%maxn;
	return 0;
}
