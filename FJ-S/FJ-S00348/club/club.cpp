#include<bits/stdc++.h>
using namespace std;
int t,n;
struct s{
	long long r1,r2,r3;
	long long cha;
}a[100005];
int cmp(s x,s y){
	return x.r1>y.r1;
}
int cmp1(s x,s y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int flag=1,flag1=1;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].r1,&a[i].r2,&a[i].r3);
			a[i].cha=a[i].r1-a[i].r2;
			if(a[i].r2!=0||a[i].r3!=0){
				flag=0;
			}
			if(a[i].r3!=0){
				flag1=0;
			}
		}
		if(n==2){
			ans=max(a[1].r1+a[2].r2,a[1].r1+a[2].r3);
			ans=max(ans,max(a[1].r2+a[2].r1,a[1].r2+a[2].r3));
			ans=max(ans,max(a[1].r3+a[2].r1,a[1].r3+a[2].r2));
			printf("%lld\n",ans);
			continue;
		}
		sort(a+1,a+n+1,cmp);
		if(flag==1){
			for(int i=1;i<=n/2;i++){
				ans=ans+a[i].r1;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(flag1==1){
			long long f1=0,f2=0,fe1=0,fe2=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(a[i].cha>=0){
					f1++;
					fe1=fe1+a[i].r1;
				}else{
					f2++;
					fe2=fe2+a[i].r2;
				}
			}
			if(f1==f2){
				printf("%lld\n",fe1+fe2);
				continue;
			}else if(f1<f2){
				for(int i=f1+1;i<=n/2;i++){
					fe1=fe1+a[i].r1;
					fe2=fe2-a[i].r2;
				}
				printf("%lld\n",fe1+fe2);
				continue;
			}else{
				for(int i=f2+1;i<=n/2;i++){
					fe1=fe1-a[i].r1;
					fe2=fe2+a[i].r2;
				}
				printf("%lld\n",fe1+fe2);
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			ans=ans+max(a[i].r1,max(a[i].r2,a[i].r3));
		}
		printf("%lld\n",ans);
	}
	return 0;
}