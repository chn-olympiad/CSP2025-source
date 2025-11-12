#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		long long n,c=0,sum=0,x,y,z,d=0,b=0,a2[50001]={},b2[50001]={},c2[50001]={};
		scanf("%lld",&n);
		for(int i=0;i<n;i++){
			scanf("%lld %lld %lld",&x,&y,&z);
			long long maxn=max(max(x,y),z);
			sum+=maxn;
			if(n==1){
				continue;
			}
			if(maxn==x){
				d++;
				if(d>n/2){
					d--;
					sort(a2,a2+d);
					if(maxn<=a2[0]){
						sum-=maxn;
						sum+=max(y,z);
					}else{
						sum-=a2[0];
						a2[0]=maxn;
					}
				}else{
					a2[d-1]=maxn;
				}
			}else if(maxn==y){
				b++;
				if(b>n/2){
					b--;
					sort(b2,b2+b);
					if(maxn<=b2[0]){
						sum-=maxn;
						sum+=max(x,z);
					}else{
						sum-=b2[0];
						b2[0]=maxn;
					}
				}else{
					b2[b-1]=maxn;
				}
			}else{
				c++;
				if(c>n/2){
					
					c--;
					sort(c2,c2+c);
					if(maxn<=c2[0]){
						sum-=maxn;
						sum+=max(x,y);
					}else{
						sum-=c2[0];
						c2[0]=maxn;
					}
				}else{
					c2[c-1]=maxn;
				}
			}
			
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
