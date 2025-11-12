#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=998224353;
long long n,a[N],ans,z[N];
bool vis[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	printf("%lld",(unsigned long long)((n*n-n)/2)%mod);
	
	
	return 0;
}

