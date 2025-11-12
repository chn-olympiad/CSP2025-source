//GZ-S00380 遵义市第四中学 胡明轩 
#include<bits/stdc++.h>
using namespace std;
struct cj{
	int x,y,z,q;
}a[100005];
int cmp(cj m,cj nn){
	return m.x>nn.x;
}
int t,n,sum=0,t1=0,t2=0,t3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0,t1=0,t2=0,t3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i].q=max(a[i].x,max(a[i].y,a[i].z));
		} 
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].q==a[i].x){
				int w=max(a[i].y,a[i].z);
				if((t1+1==n/2 &&a[i+1].q==a[i+1].x)&&w+a[i+1].x>a[i].x){
					sum+=w;
					if(w==a[i].y)	t2++;
					else	t3++;
				}
				else{
					t1++;
					sum+=a[i].q;
				}
			}else if(a[i].q==a[i].y){
				int w=max(a[i].x,a[i].z);
				if((t2+1==n/2 &&a[i+1].q==a[i+1].y)&&w+a[i+1].y>a[i].y){
					sum+=w;
					if(w==a[i].x){
						t1++;
					}else{
						t3++;
					}
				}else{
					t2++;
					sum+=a[i].q;
				}
			}else{
				int w=max(a[i].x,a[i].y);
				if((t3+1==n/2 &&a[i+1].q==a[i+1].z)&&w+a[i+1].z>a[i].z){
					sum+=w;
					if(w==a[i].x){
						t1++;
					}else{
						t2++;
					}
				}else{
					t3++;
					sum+=a[i].q;
				}
			}
		}
	printf("%d",sum);	 
	}
	return 0;
} 
