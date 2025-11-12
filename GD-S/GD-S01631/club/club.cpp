#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	long long t1=t,ans[t+5];
	while(t--){
		ans[t]=0;
		long long int n;
		cin>>n;
		long long ma[4][n+5],max[n+5],u[4]={0,0,0,0},op1[n+5],op2[n+5],op3[n+5];
		for(int i=0;i<n;i++){
			op1[i]=10000000;
			op2[i]=11111111;
			op3[i]=11111111;
			max[i]=0;
			for(int j=1;j<=3;j++){
				cin>>ma[j][i];
			}
			if(ma[1][i]>=ma[2][i]&ma[1][i]>=ma[3][i]){
				max[i]=ma[1][i];
				u[1]++;
				if(ma[2][i]>=ma[3][i]){
					op1[i]=ma[1][i]-ma[2][i];
				}
				else{
					op1[i]=ma[1][i]-ma[3][i];
				}
			}
			else if(ma[2][i]>=ma[3][i]){
				max[i]=ma[2][i];
				u[2]++;
				if(ma[3][i]>=ma[1][i]){
					op2[i]=ma[2][i]-ma[3][i];
				}
				else{
					op2[i]=ma[2][i]-ma[1][i];
				}
			}
			else{
				max[i]=ma[3][i];
				u[3]++;
				if(ma[1][i]>=ma[2][i]){
					op3[i]=ma[3][i]-ma[1][i];
				}
				else{
					op3[i]=ma[3][i]-ma[2][i];
				}
			}
			ans[t]+=max[i];
		}
	for(int q=1;q<4;q++){
			if(u[q]>n/2){
			if(q==1){
				sort(op1,op1+n);
				for(int i=0;i<u[q]-n/2;i++){
						ans[t]-=op1[i];
					}
				}
				else if (q==2){
					sort(op2,op2+n);
					
					for(int i=0;i<u[q]-n/2;i++){
						
						ans[t]-=op2[i];
					}
				}
				else{
					sort(op3,op3+n);
					for(int i=0;i<u[q]-n/2;i++){
						ans[t]-=op3[i];
					}
				}
			}
		}			
	}
	while(t1--){
		cout<<ans[t1]<<endl;
	}
	return 0;
} 
