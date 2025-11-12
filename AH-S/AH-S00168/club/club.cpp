#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][3],f,b[100005],s;
void dfs(long long x,long long y,long long z,long long r,long long g){
	if(x>n/2||y>n/2||z>n/2) return;
	if(r-n==1) s=max(s,g);
	else if(r>n) return;
	dfs(x+1,y,z,r+1,g+a[r][0]);
	dfs(x,y+1,z,r+1,g+a[r][1]);
	dfs(x,y,z+1,r+1,g+a[r][2]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		s=0;
		f=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][2]) f=1;
		}
		if(f) dfs(0,0,0,1,0);
		else{
			for(long long i=1;i<=n;i++){
				s+=a[i][0];
				b[i]=a[i][0]-a[i][1];
			}
			sort(b+1,b+1+n);
			for(long long i=1;i<=n/2;i++) s-=b[i];
		}
		printf("%lld\n",s);
	}
	return 0;
}
