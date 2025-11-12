#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,as[N],ass=0,bs[N],bss=0,cs[N],css=0,su=0;
	scanf("%d",&t);
	while(t--){
		ass=0;
		bss=0;
		css=0;
		su=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i][0]);
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			if(a[i][0]>=a[i][1]){
				if(a[i][0]>=a[i][2]){
					as[ass]=i;
					ass++;
					su+=a[i][0];
				}
				else{
					cs[css]=i;
					css++;
					su+=a[i][2];
				}
			}
			else if(a[i][1]>=a[i][0]){
				if(a[i][1]>=a[i][2]){
					bs[bss]=i;
					bss++;
					su+=a[i][1];
				}
				else{
					cs[css]=i;
					css++;
					su+=a[i][2];
				}
			}
		}
		int ghj=n/2;
		if(ass>=ghj){
			sort(as,as+ass);
			for(int i=0;i<ass-ghj;i++){
				su-=a[i][0];
				if(a[i][1]>=a[i][2]){
					su+=a[i][1];
				}
				else{
					su+=a[i][2];
				}
			}
		}
		else if(bss>=ghj){
			sort(bs,bs+bss);
			for(int i=0;i<bss-ghj;i++){
				su-=a[i][1];
				if(a[i][0]>=a[i][2]){
					su+=a[i][0];
				}
				else{
					su+=a[i][2];
				}
			}
		}
		else{
			sort(cs,cs+css);
			for(int i=0;i<css-ghj;i++){
				su-=a[i][2];
				if(a[i][0]>=a[i][1]){
					su+=a[i][0];
				}
				else{
					su+=a[i][1];
				}
			}
		}
		printf("%d\n",su);
	}
	return 0;
}
