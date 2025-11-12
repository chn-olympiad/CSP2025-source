#include <bits/stdc++.h>
using namespace std;
long long T,n,sum,a[100010][5],k,gs[10],pos[100010],r[10],p[100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		sum=0;
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			k=-1e9;
			for(int j=1;j<=3;j++){
				if(a[i][j]>=k){
					k=a[i][j];
					if(j==1){
						gs[j]++;
						sum+=a[i][j];
						pos[i]=j;
						r[j]++;
					}
					else{
						gs[j]++;
						gs[pos[i]]--;
						sum+=a[i][j];
						sum-=a[i][pos[i]];
						r[j]++;
						r[pos[i]]--;
					}
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
