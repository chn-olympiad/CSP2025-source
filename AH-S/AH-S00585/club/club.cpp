#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3];
int maxx(int x,int y,int z){
	return max(x,max(y,z));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0,sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}	
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]==maxx(a[i][1],a[i][2],a[i][3])){
				if(sum1!=n/2){
					sum1++;
					ans+=a[i][1];
				}
				else{
					if(a[i][2]==max(a[i][2],a[i][3])){
						if(sum2!=n/2){
							sum2++;
							ans+=a[i][2];
						}
						else if(sum3!=n/2){
							sum3++;
							ans+=a[i][3];
						}
						else break;		
					}
					else if(a[i][3]==max(a[i][2],a[i][3])){
						if(sum3!=n/2){
							sum3++;
							ans+=a[i][3];
						}
						else if(sum2!=n/2){
							sum2++;
							ans+=a[i][2];
						}
						else break;		
					}		
				}		
			}
			if(a[i][2]==maxx(a[i][1],a[i][2],a[i][3])){
				if(sum2!=n/2){
					sum2++;
					ans+=a[i][2];
				}
				else{
					if(a[i][1]==max(a[i][1],a[i][3])){
						if(sum1!=n/2){
							sum1++;
							ans+=a[i][1];
						}
						else if(sum3!=n/2){
							sum3++;
							ans+=a[i][3];
						}
						else break;		
					}
					else if(a[i][3]==max(a[i][1],a[i][3])){
						if(sum3!=n/2){
							sum3++;
							ans+=a[i][3];
						}
						else if(sum1!=n/2){
							sum1++;
							ans+=a[i][1];
						}
						else break;		
					}		
				}		
			}
			if(a[i][3]==maxx(a[i][1],a[i][2],a[i][3])){
				if(sum3!=n/2){
					sum3++;
					ans+=a[i][3];
				}
				else{
					if(a[i][2]==max(a[i][2],a[i][1])){
						if(sum2!=n/2){
							sum2++;
							ans+=a[i][2];
						}
						else if(sum1!=n/2){
							sum1++;
							ans+=a[i][1];
						}
						else break;		
					}
					else if(a[i][1]==max(a[i][2],a[i][1])){
						if(sum1!=n/2){
							sum1++;
							ans+=a[i][1];
						}
						else if(sum2!=n/2){
							sum2++;
							ans+=a[i][2];
						}
						else break;		
					}		
				}		
		    }				
		}
		printf("%d\n",ans);	
	}	
	return 0;
}
