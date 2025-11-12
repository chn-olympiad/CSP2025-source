#include<bits/stdc++.h>
using namespace std;
const int N=1e5+500;
int t,n;
int ans,aa1,aa2,aa3,cut,b[N];
struct pers{
	int a1,a2,a3;
	int maxa;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=aa1=aa2=aa3=cut=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j].a1,&a[j].a2,&a[j].a3);
			ans+=max(a[j].a1,max(a[j].a2,a[j].a3));
			if(a[j].a1>=a[j].a2&&a[j].a1>=a[j].a3){
				aa1++;
				a[j].maxa=1;
			}else if(a[j].a2>=a[j].a1&&a[j].a2>=a[j].a3){
				aa2++;
				a[j].maxa=2;
			}else{
				aa3++;
				a[j].maxa=3;
			}
		}
		if(aa1>n/2){
			for(int j=1;j<=n;j++){
				if(a[j].maxa==1){
					b[++cut]=min(a[j].a1-a[j].a2,a[j].a1-a[j].a3);
				}
			}
			sort(b+1,b+cut+1);
			for(int j=1;j<=aa1-n/2;j++){
				ans-=b[j];
			}
		}else if(aa2>n/2){
			for(int j=1;j<=n;j++){
				if(a[j].maxa==2){
					b[++cut]=min(a[j].a2-a[j].a1,a[j].a2-a[j].a3);
				}
			}
			sort(b+1,b+cut+1);
			for(int j=1;j<=aa2-n/2;j++){
				ans-=b[j];
			}
		}else if(aa3>n/2){
			for(int j=1;j<=n;j++){
				if(a[j].maxa==3){
					b[++cut]=min(a[j].a3-a[j].a1,a[j].a3-a[j].a2);
				}
			}
			sort(b+1,b+cut+1);
			for(int j=1;j<=aa3-n/2;j++){
				ans-=b[j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
