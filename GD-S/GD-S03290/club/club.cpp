#include<bits/stdc++.h>
using namespace std;
int t,n,a[300055],vis[3];
long long ans=0;
void f(int x,long long m){
	if(x==n){
		ans=max(ans,m);
		return;
	}
	for(int i=0;i<3;i++){
		if(vis[i]<n/2){
			vis[i]+=1;
			f(x+1,m+a[x*3+i]);
			vis[i]-=1;
		}
			
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&a[i*3],&a[i*3+1],&a[i*3+2]);
		}
		f(0,0);
		printf("%ld\n",ans);
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
