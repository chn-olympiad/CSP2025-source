#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=1e6+5;
int a[MAXN][3];
int p[MAXN];
int n;
int b[3][MAXN],len[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ll ans=0;
		scanf("%d",&n);
		len[0]=len[1]=len[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				ans+=a[i][0];
				b[0][++len[0]]=a[i][0]-max(a[i][1],a[i][2]);
			}else{
				if(a[i][1]>=a[i][0]&&a[i][1]>a[i][2]){
					ans+=a[i][1];
					b[1][++len[1]]=a[i][1]-max(a[i][0],a[i][2]);
				}else{
					ans+=a[i][2];
					b[2][++len[2]]=a[i][2]-max(a[i][1],a[i][0]);	
				}
			}
		} 
		sort(b[0]+1,b[0]+1+len[0]);
		sort(b[1]+1,b[1]+1+len[1]);
		sort(b[2]+1,b[2]+1+len[2]); 
		for(int i=0;i<=2;i++){
			
			if(len[i]>n/2){
	//			printf("remake %d\n",i);
				for(int j=1;j<=len[i]-n/2;j++){
	//				printf("%d ",b[i][j]);
					ans-=b[i][j];
				}
			}	
		}printf("%lld\n",ans);
	}
} 
