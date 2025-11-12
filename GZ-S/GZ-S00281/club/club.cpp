// GZ-S00281 毕节梁才学校 柯睿贤 
#include <bits/stdc++.h>
using namespace std;
int T,n;
int main(){  
	freopen ("club.in","r",std);
	freopen ("club.out","w",std);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			/*if(x>=y&&x>=z){
				if()
			}*/
			/*if(x>=y && x>=z){
				if(a>=n/2){
					sum+=max(y,z);
					if(y>=z) b++;
					else c++;
				}else{
					a++;
					sum+=x; 
				}
			}
			else if(y>=x&& y>=z){
				
			}
			else{
				
				}
			}*/
		} 
		printf("%d\n",sum);
	}
	return 0;
}
