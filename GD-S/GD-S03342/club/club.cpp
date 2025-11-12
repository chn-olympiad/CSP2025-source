#include<bits/stdc++.h>
using namespace std;
long long t;
long long a[20001][4],n,b[20001];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				scanf("%lld",&a[j][k]);
			}
		}
		long long ans=0,q=0;
		for(int j=1;j<=n;j++){
			long long c=0;long long e=0;
			for(int k=1;k<=3;k++){
				if(b[k]<n/2){
					if(c<a[j][k]){
						if(e>0){
							b[e]-=1;
						}
						c=a[j][k];
						b[k]++;
						
						e=k;
					}
				}
			}
			q+=c;
		}
		b[1]=0;b[2]=0,b[3]=0;
		for(int j=n;j>=1;j--){
			long long c=0;long long e=0;
			for(int k=3;k>=1;k--){
				if(b[k]<n/2){
					if(c<a[j][k]){
						if(e>0){
							b[e]-=1;
						}
						c=a[j][k];
						b[k]++;
						
						e=k;
					}
				}
			}
			ans+=c;
		}
		b[1]=0;b[2]=0,b[3]=0;
		ans=max(q,ans);
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

