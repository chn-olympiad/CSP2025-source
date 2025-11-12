#include<bits/stdc++.h>
using namespace std;
long long a[5005],mod=998244353,l,cnt,n,k,book[5005];
void dfs(int xx,int x,int y,int z){
	if(y==l){
		if(z>2*x){
			cnt++;
			cnt=cnt%mod;
		}
		return ;
	}
	for(int i=xx+1;i<=n;i++){
		dfs(i,a[i],y+1,z+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long i,j,maxn;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	maxn=a[n];
	for(i=3;i<=n;i++){
		l=i;
		dfs(0,0,0,0);
	}
	printf("%d",cnt);
	
	return 0;
}
