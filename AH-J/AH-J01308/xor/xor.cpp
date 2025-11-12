#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a[105],ans0,ans1,x,ok=1;
int main (){
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==1) ans1++;
		else{
			if(a[i]==0) ans0++;
			else ok=0;
			}
		}
       /*if(n<=2&&k==0){
		if(n==1){
			if((a[1]^a[1])==k) ans++;
			}
			else{
			if(((a[1]^a[1])==k)&&((a[2]^a[2])==k)) ans++;
			if((a[1]^a[2])==k) ans++;
				}
			printf("%d",ans);
		}*/
	if(ok){
		if(k==1) printf("%d\n",ans1);\
		else printf("%d\n",ans0+ans1);
		}
		else{
			if(k==0) printf("%d\n",n);
			}
    return 0;
}
