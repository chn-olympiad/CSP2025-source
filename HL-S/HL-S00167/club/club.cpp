#include<bits/stdc++.h>
using namespace std;
int a[3];
int b[100005][3]; 
int ans[5];
int main(){
	
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	int t,n,x=0;
	cin>>t;
	for(int s=1; s<=t; s++){
		cin>>n;
		for(int i =1; i<=n; i++){
			for(int j=1; j<=3; j++){
				cin>>b[i][j];
		    }
		    x=0;
			if(b[i][1]<b[i][2]){
				swap(b[i][1],b[i][2]);
				x++;
			}
			if(b[i][3]>b[i][1]){
				swap(b[i][3],b[i][1]);
				x++;
			}//排序，b[j][1]是最大值 
			if(x==2){
				a[3]+=1;
			}else if(x==1){
				a[2]+=1;
			}else{
				a[1]+=1;
			}//算出每个小组的人数 a[i]	
	
			if(a[1]<=n/2){
				ans[i]+=b[i][1];
			}else{
				
			}
			if(a[2]<=n/2){
				ans[i]+=b[i+1][1];
			}
			if(a[3]<=n/2){
				ans[i]+=b[i+2][1];
			}
	}
	}
	
	
	for(int i=1; i<=t; i++){
		cout << ans[i];
		cout << endl;
		
	}	
	
	return 0; 
}
