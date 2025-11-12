#include<cstdio>
bool can[500005];
int x,y[500005],dp[500005],want,t=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&x,&want);
	for(int a(1);a<=x;++a){
		scanf("%d",&y[a]);
		if(y[a]==want){
			can[a]=1;
			dp[a]=-1;
			t++;
		}
		if(a!=1 && !can[a]){
			if(can[a-1]) dp[a]=y[a];
			else dp[a]=y[a]^dp[a-1];
		}
		else if(a==1 && !can[1]){
			dp[1]=y[1];
		}
	}
//	if(!can[1]) dp[1]=y[1];
//	for(int a(1);a<=x;++a){
//		printf("dp[%d]:%d ",a,dp[a]);
//	}
//	printf("\n");
//	for(int a(1);a<=x;++a){
//		printf("can[%d]:%d ",a,can[a]);
//	}
//	printf("\n");
	for(int a(2);a<=x;++a){
		if(dp[a]==-1 || can[a]) continue;
		for(int r(1);r<a;++r){
			if(dp[r]==-1 || can[r]) continue;
//			if(dp[r-1]!=-1){
//				printf("a:%d r:%d %d\n",a,r,dp[a]^dp[r-1]);
//			}
//			else{
//				printf("a:%d r:%d %d\n",a,r,dp[r]^dp[a]^dp[r]);
//			}
			if(dp[r-1]!=-1){
				if((dp[r-1]^dp[a])==want){
					t++;
					for(int z(r);z<=a;++z){
						can[z]=1;
					}
				}
			}
			else{
				if((dp[r]^dp[a]^dp[r])==want){
					t++;
					for(int z(r);z<=a;++z){
						can[z]=1;
					}
				}
			}
		}
	}
//	printf("\n");
//	for(int a(1);a<=x;++a){
//		printf("dp[%d]:%d ",a,dp[a]);
//	}
//	printf("\n");
//	for(int a(1);a<=x;++a){
//		printf("can[%d]:%d ",a,can[a]);
//	}
//	printf("\n");
	printf("%d",t);
	return 0;
}
