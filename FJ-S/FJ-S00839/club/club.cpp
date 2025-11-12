#include<bits/stdc++.h>
using namespace std;
int a[2][3],max1=0,max2=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<2;j++){
			for(int w=0;w<=2;w++){
			cin>>a[j][w];				
			}
		}			
		max1=max(max(a[0][0],a[0][1]),a[0][2]);
		max2=max(max(a[1][0],a[1][1]),a[1][2]);
		cout<<max1<<" "<<max2;
		if(max1==a[0][0]&&max2==a[1][0]){
			if(max1>max2){
				max2=max(a[1][1],a[1][2]);
			}else if(max1<max2){
				max1=max(a[0][1],a[0][2]);	
			}else if(max1==max2){
			    if(max(a[0][1],a[0][2])>max(a[1][1],a[1][2])){
			    	max2=max(a[1][1],a[1][2]);
				}else if(max(a[0][1],a[0][2])<=max(a[1][1],a[1][2])){
			    	max1=max(a[0][1],a[0][2]);
				}
			}
		}else if(max1==a[0][1]&&max2==a[1][1]){
			if(max1>max2){
				max2=max(a[1][0],a[1][2]);
			}else if(max1<max2){
				max1=max(a[0][0],a[0][2]);	
			}else if(max1==max2){
			    if(max(a[0][0],a[0][2])>max(a[1][0],a[1][2])){
			    	max2=max(a[1][0],a[1][2]);
				}else if(max(a[0][0],a[0][2])<=max(a[1][0],a[1][2])){
			    	max1=max(a[0][0],a[0][2]);
				}
			}
		}else if(max1==a[0][2]&&max2==a[1][2]){
			if(max1>max2){
				max2=max(a[1][1],a[1][0]);
			}else if(max1<max2){
				max1=max(a[0][1],a[0][0]);	
			}else if(max1==max2){
			    if(max(a[0][1],a[0][0])>max(a[1][1],a[1][0])){
			    	max2=max(a[1][1],a[1][0]);
				}else if(max(a[0][1],a[0][0])<=max(a[1][1],a[1][0])){
			    	max1=max(a[0][1],a[0][0]);
				}
			}
		}
		cout<<max1+max2<<endl;
	}
	return 0;
}
