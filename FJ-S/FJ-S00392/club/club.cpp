#include<bits/stdc++.h>
using namespace std;
int b[100][100]={};
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,a1,a2,a3;
	cin>>t;
	int sum[1000]={};
	for(int i=1;i<=t;i++){
		int n=0,people1=0,people2=0,people3=0;
		cin>>n;
		if(n%2!=0){
			break;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>b[j][k];
			}
		}
		for(int j=1;j<=n;j++){
				a1=b[j][1];
				a2=b[j][2];
				a3=b[j][3];
				if(a1>a2&&a1>a3){
					if(people1<=n/2){
						sum[i]+=a1;
						people1++;
					}
				}
				if(a2>a1&&a2>a3){
					if(people2<=n/2){
						sum[i]+=a2;
						people2++;
					}
				}
				if(a3>a1&&a3>a2){
					if(people3<=n/2){
						sum[i]+=a3;
						people3++;
					}
				}	
		}
		cout<<sum[i]<<endl;
	}
return 0;
}
