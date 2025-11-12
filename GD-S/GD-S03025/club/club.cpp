#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N=1e5+5,Ne2=2e2+5;
int T;
int n;
int f[Ne2][Ne2];
int b[N];
int a[N][3];
int ans;
void main_(){
	scanf("%d",&n);
	int s0=0,s1=0,s2=0;
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		s0+=a[i][0];
		s1+=a[i][1];
		s2+=a[i][2];
	}
	if(s1==0&&s2==0){
		for(int i=1; i<=n; i++){
			b[i]=a[i][0];
		}
		sort(b+1,b+n+1);
		ans=0;
		for(int i=n/2+1; i<=n; i++){
			ans+=b[i];
		}
		printf("%d\n",ans);
		return;
	}
	if(s2==0){
		for(int i=1; i<=n; i++){
			b[i]=a[i][1]-a[i][0];
		}
		sort(b+1,b+n+1);
		ans=s0;
		for(int i=n/2+1; i<=n; i++){
			ans+=b[i];
		}
		printf("%d\n",ans);
		return;
	}
	if(n>200){
		ans=0;
		for(int i=1; i<=n; i++){
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		printf("%d\n",ans);
		return;
	}
//	int c0=0,c1=0,c2=0;
//	int c01=0,c02=0,c12=0;
//	int c012=0;
//	for(int i=1; i<=n; i++){
//		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
//			c0++;
//		}
//		if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
//			c1++;
//		}
//		if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]){
//			c2++;
//		}
//		if(a[i][0]==a[i][1]&&a[i][0]>a[i][2]){
//			c01++;
//		} 
//		if(a[i][0]==a[i][2]&&a[i][0]>a[i][1]){
//			c02++;
//		}
//		if(a[i][1]==a[i][2]&&a[i][1]>a[i][0]){
//			c12++;
//		}
//		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]){
//			c012++;
//		}
//	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			f[i][j]=-inf;
		}
	}
	f[0][0]=0;
	for(int i=1; i<=n; i++){
		for(int j=min(n/2,i); j>=0; j--){
			for(int k=min(n/2,i); k>=0; k--){
				f[j][k]+=a[i][2];
				if(j){
					f[j][k]=max(f[j][k],f[j-1][k]+a[i][0]);
				}
				if(k){
					f[j][k]=max(f[j][k],f[j][k-1]+a[i][1]);
				}
			}
		}
	}
	ans=-inf;
	for(int j=0; j<=n/2; j++){
		for(int k=0; k<=n/2; k++){
			if(n-j-k<=n/2){
				ans=max(ans,f[j][k]);
			}
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		main_();
	}
	return 0;
}
