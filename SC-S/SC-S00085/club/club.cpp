#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
struct R{
	int a,b,c,i,p,st,nd,cz,w;//平均值 最大 第二大 第一与第二的差值 最想去哪个部门
}a[100010];
bool cmp(R x,R y){
	return x.cz<y.cz;
}
lld t,n,ans;int f[100010],tj[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			lld max1=max(max(a[i].a,a[i].b),a[i].c);
			a[i].i=i;
			if(a[i].a==max1){
				a[i].w=1;
				a[i].st=a[i].a;
				if(a[i].b>a[i].c){
					a[i].nd=a[i].b;
				}else{
					a[i].nd=a[i].c;
				}
			}
			if(a[i].b==max1){
				a[i].w=2;
				a[i].st=a[i].b;
				if(a[i].a>a[i].c){
					a[i].nd=a[i].a;
				}else{
					a[i].nd=a[i].c;
				}
			}
			if(a[i].c==max1){
				a[i].w=3;
				a[i].st=a[i].c;
				if(a[i].a>a[i].b){
					a[i].nd=a[i].a;
				}else{
					a[i].nd=a[i].b;
				}
			}
			a[i].cz=a[i].st-a[i].nd;
			a[i].p=a[i].a+a[i].b+a[i].c;
		}
		//先贪心
		lld max1=n/2;
		ans=0;int g,gl;
		tj[1]=0,tj[2]=0,tj[3]=0;
		for(int i=1;i<=n;i++){
			if(a[i].w==1)tj[1]++,ans+=a[i].st;
			else if(a[i].w==2)tj[2]++,ans+=a[i].st;
			else if(a[i].w==3)tj[3]++,ans+=a[i].st;
		}
		if((tj[1]<=max1)&&(tj[2]<=max1)&&(tj[3]<=max1)){
			printf("%lld\n",ans);
			continue;
		}else{
			if(tj[1]>max1)g=1;
			if(tj[2]>max1)g=2;
			if(tj[3]>max1)g=3;
			gl=tj[g]-max1;
		}
		//拿不到最大值
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].w==g){
				ans-=a[i].cz;
				gl--;
				if(gl==0)break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}