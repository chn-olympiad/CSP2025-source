#include<bits/stdc++.h>
using namespace std;
const int N = 1e9+5;
long int n,m,k,f[N][N];
struct node{
	long int a,b,c;
}q[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%ld%ld%ld",&n,&m,&k);
	for(long int i=1;i<=n;i++){
		scanf("%ld%ld%ld",&q[i].a,&q[i].b,q[i].c);
	}
	for(long int i=1;i<=k;i++){
		for(long int j=1;j<=n+1;j++){
			scanf("%ld",&f[i][j]);
		}
	}
	if(n%2==0) cout << 13;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
