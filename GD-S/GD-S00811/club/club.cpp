#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int t;
struct u{
	long long myd,bh,st;//满意度，编号，社团 
};
bool cmp(u x,u y){
	if (x.bh!=y.bh) return x.bh<y.bh;
	return x.myd>y.myd;
}
u a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		int n,mx,an,bn,cn,k=0;
		int sum[4]={0,0,0,0};
		long long ans=0;
		an=bn=cn=0;
		cin>>n;
		mx=n/2;
		for (int i=1;i<=n*3;i+=3){
			cin>>a[i].myd>>a[i+1].myd>>a[i+2].myd;
			a[i].st=1;a[i+1].st=2;a[i+2].st=3;
			a[i].bh=a[i+1].bh=a[i+2].bh=i/3+1;
		}
		sort(a+1,a+1+n*3,cmp);
//		for (int i=1;i<=n*3;i++){
//			cout<<a[i].myd<<' '<<a[i].bh<<endl;
//		}
		for (int i=1;i<=n*3;i+=3){
			ans+=a[i].myd;
			//printf("ans:%lld\n",ans);
			sum[a[i].st]++;
		}
		for (int i=1;i<=3;i++){
			//printf("sum[%d]:%d\n",i,sum[i]);
			if (sum[i]>mx){
				int b[N],k=0,next;
				
				for (int j=1;j<=n*3;j+=3){
					if (j%3==0) next=j-2;
					else next=j+1;
					if (a[j].st==i){
						b[++k]=a[j].myd-a[next].myd;
						//printf("a[%d].myd:%d a[%d].myd:%d\n",j ,a[j].myd,next,a[next].myd);
					}
				}
				sort(b+1,b+1+k);
				for (int j=1;j<=k;j++){
					//printf("b[j]:%d\n",b[j]);
					if (sum[i]<=mx) break;
					ans-=b[j];
					//printf("ans:%lld\n",ans);
					sum[i]--;
					sum[next]++;
				}
			}
			
		}
		for (int i=1;i<=3;i++){
			//printf("sum[%d]:%d\n",i,sum[i]);
			if (sum[i]>mx){
				int b[N],k=0,next;
				
				for (int j=1;j<=n*3;j+=3){
					if (j%3==0) next=j-2;
					else next=j+1;
					if (a[j].st==i){
						b[++k]=a[j].myd-a[next].myd;
						//printf("a[%d].myd:%d a[%d].myd:%d\n",j ,a[j].myd,next,a[next].myd);
					}
				}
				sort(b+1,b+1+k);
				for (int j=1;j<=k;j++){
					//printf("b[j]:%d\n",b[j]);
					if (sum[i]<=mx) break;
					ans-=b[j];
					//printf("ans:%lld\n",ans);
					sum[i]--;
					sum[next]++;
				}
			}
			
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
