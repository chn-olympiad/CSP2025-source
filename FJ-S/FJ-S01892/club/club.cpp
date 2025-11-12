#include <cstdio>
#include <algorithm>
using namespace std;
int b[100005];
struct oo{
	int aa,bb,cc;
	int a1,b1,c1;
}d[100005];
bool cmp1(oo x,oo y){
	return x.a1 >y.a1 ;	
}
bool cmp2(oo x,oo y){
	return x.b1 >y.b1 ;	
}
bool cmp3(oo x,oo y){
	return x.c1 >y.c1 ;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int flag=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i].aa,&d[i].bb,&d[i].cc);
			if(d[i].bb!=0||d[i].cc!=0){
				flag=1;
			}
		}
		if(flag==0){
			for(int i=1;i<=n;i++){
				b[i]=d[i].aa;
			}
			sort(b+1,b+n+1);
			long long sum=0;
			for(int i=n;i>=(n/2)+1;i--){
				sum+=b[i];
			}
			printf("%lld\n",sum);
		}else{
			long long sum1=0,sum2=0,sum3=0,sum4=0;
			for(int i=1;i<=n;i++){
				sum1+=d[i].aa;
				sum2+=d[i].bb;
				sum3+=d[i].cc;
				d[i].a1 =((d[i].bb-d[i].aa)>(d[i].cc-d[i].aa))?(d[i].bb-d[i].aa):(d[i].cc-d[i].aa);
				d[i].b1 =((d[i].cc-d[i].bb)>(d[i].aa-d[i].bb))?(d[i].cc-d[i].bb):(d[i].aa-d[i].bb);
				d[i].c1 =((d[i].bb-d[i].cc)>(d[i].aa-d[i].cc))?(d[i].bb-d[i].cc):(d[i].aa-d[i].cc);
//				printf("%d %d %d\n",d[i].a1 ,d[i].b1,d[i].c1);
			} 
			sort(d+1,d+n+1,cmp1);
			for(int i=1;i<=(n/2);i++){
				sum1+=d[i].a1;
			}
			sort(d+1,d+n+1,cmp2);
			for(int i=1;i<=(n/2);i++){
				sum2+=d[i].b1;
			}	
			sort(d+1,d+n+1,cmp3);
			for(int i=1;i<=(n/2);i++){
				sum3+=d[i].c1;
			}	
			int n1=0,n2=0,n3=0;
			for(int i=1;i<=n;i++){
				if(d[i].aa>=d[i].bb&&d[i].aa>=d[i].cc){
					n1++;
					sum4+=d[i].aa;
				}else if(d[i].bb>=d[i].aa&&d[i].bb>=d[i].cc){
					n2++;
					sum4+=d[i].bb;
				}else{
					n3++;
					sum4+=d[i].cc;
				}
			}
			long long ans=0;
			if(sum1>=sum2&&sum1>=sum3){
				ans=sum1;
			}else if(sum2>=sum1&&sum2>=sum3){
				ans=sum2;
			}else{
				ans=sum3;
			}	
			if(n1>(n/2)||n2>(n/2)||n3>(n/2)){
				printf("%lld\n",ans);
			}else{
				printf("%lld\n",sum4);
			}
		}
		for(int i=1;i<=n;i++){
			d[i].aa=d[i].bb=d[i].cc=0;
		}
	}
	return 0;
} 
