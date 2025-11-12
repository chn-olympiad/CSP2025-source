//GZ-S00410 清镇市博雅实验学校 许秉轩 
#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[10050][8],b[10050][8];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int l=0;l<n;l++){
			for(int k=0;k<3;k++){
				cin>>a[l][k];
				a[l][4]=max( (max(a[l][1],a[l][2])),max(a[l][2],a[l][3]) );
				if(a[l][1]==a[l][4]){
					a[l][5]=max(a[l][2],a[l][3]);
				}
				if(a[l][2]==a[l][4]){
					a[l][5]=max(a[l][1],a[l][3]);
				}
				if(a[l][3]==a[l][4]){
					a[l][5]=max(a[l][2],a[l][1]);
				}
			}
		}
		
		
		for(int l=0;l<n;l++){
			for(int k=0;k<3;k++){
				
			}
		}
		
	}
	return 0;
}
