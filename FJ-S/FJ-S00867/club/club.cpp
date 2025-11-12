#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],ans,q1[N],q2[N],q3[N],t1,t2,t3,b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;t1=0,t2=0,t3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				q1[++t1]=i;
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				q2[++t2]=i;
				ans+=a[i][2];
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				q3[++t3]=i;
				ans+=a[i][3];
			}
		}
		if(t1*2>n){
			for(int i=1;i<=t1;i++){
				b[i]=a[q1[i]][1]-(max(a[q1[i]][2],a[q1[i]][3]));
			}
			sort(b+1,b+1+t1);
			for(int i=1;i<=t1-ceil(n/2.0);i++){
				ans-=b[i];
			}
		}
		else if(t2*2>n){
			for(int i=1;i<=t2;i++){
				b[i]=a[q2[i]][2]-(max(a[q2[i]][1],a[q2[i]][3]));
			}
			sort(b+1,b+1+t2);
			for(int i=1;i<=t2-ceil(n/2.0);i++){
				ans-=b[i];
			}
		}
		else if(t3*2>n){
			for(int i=1;i<=t3;i++){
				b[i]=a[q3[i]][3]-(max(a[q3[i]][1],a[q3[i]][2]));
			}
			sort(b+1,b+1+t3);
			for(int i=1;i<=t3-ceil(n/2.0);i++){
				ans-=b[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
