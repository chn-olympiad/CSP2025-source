#include <bits/stdc++.h>
using namespace std;
long long t,a[100010][5],ans,m,n;
void awa(long long x,long long y,long long z,long long sum,long long k){
	if(x>m||y>m||z>m)return;
	ans=max(ans,sum);
	for(int i=k+1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(j==1)awa(x+1,y,z,sum+a[i][j],k+1);
			else if(j==2)awa(x,y+1,z,sum+a[i][j],k+1);
			else if(j==3)awa(x,y,z+1,sum+a[i][j],k+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		m=n;
		m/=2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		awa(0,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
} 
