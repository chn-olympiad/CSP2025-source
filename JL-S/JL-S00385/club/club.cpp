#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n;
long long a[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				for(int x=1;x<=3;x++){
					for(int y=1;y<=3;y++){
						if(x==y)
							continue;
						ans=max(ans,a[i][x]+a[j][y]);
					}
				} 
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
