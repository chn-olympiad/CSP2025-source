#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int a[100000],b[100000],c[100000];
	int a1,b1,c1;
	int t;
	scanf("%d",&t);
	int x,y = n / 2,num = 0;
	while(t--){
		scanf("%d",&n);
		num = 0;
		a1 = 0,b1 = 0,c1 = 0;
		for(int i = 1;i <= n;i ++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			x = max(a[i], ( max(b[i],c[i]) ) );
			
			if(x == a[i]){
				if(a1 <= y){
					a1++;
					num = num + x;
					continue;
				}else{
					if(max(b[i],c[i]) == b[i]){
						b1 ++;
				        num = num + b[i];
				        continue;
					}else{
						c1++;
						num = num + c[i];
						continue;
					}
				}
			}
			
			
			if(x == b[i]){
				if(b1 <= y){
					b1++;
					num = num + x;
					continue;
				}else{
					if(max(a[i],c[i]) == a[i]){
						a1 ++;
				        num = num + a[i];
				        continue;
					}else{
						c1++;
						num = num + c[i];
						continue;
					}
				}	
			}
			
			if(x == c[i]){
				if(c1 <= y){
					c1++;
					num = num + x;
					continue;
				}else{
					if(max(a[i],b[i]) == a[i]){
						a1 ++;
				        num = num + a[i];
				        continue;
					}else{
						b1++;
						num = num + b[i];
						continue;
					}
				}
			}
			
		}
		printf("%d\n",num);
	}
	return 0;
}
