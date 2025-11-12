#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	ll ans=0;
	for(int i=1;i<=n-m+1;i++) ans += i;
	printf("%lld",ans); 
	return 0;
}

