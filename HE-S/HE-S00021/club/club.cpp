#include<iostream>
using namespace std;
long long int t,n,sum,a;
int sa[20005][50],re[20005];
int main(){

	cin>>t;

	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>sa[j][k];
			}
		}
	}
	for(int i=1;i<=t;i++){
		
		re[20005]={0};
		for(int j=1;j<=n;j++){
			sum=0;
			a=0;
			
			int a=max(sa[j][1],sa[j][2]);
			a=max(a,sa[j][3]);
			sum+=a;
			re[20005]={0};
			if(a==sa[j][1]){
				re[1]++;
			}else if(a==sa[j][2]){
				re[2]++;
			}else{
				re[3]++;
			}
			while(re[1]>(n/2)||re[2]>(n/2)||re[3]>(n/2)){
			if(re[1]>(n/2)){
				re[1]--;
				a=max(sa[j][2],sa[j][3]);
				if(a=sa[j][2]){
					re[2]++;
				}else{
					re[3]++;
				}
			}
			else if(re[2]>(n/2)){
				re[2]--;
				a=max(sa[j][1],sa[j][3]);
				if(a=sa[j][1]){
					re[1]++;
				}else{
					re[3]++;
				}
			}
			else if(re[3]>(n/2)){
				re[3]--;
				a=max(sa[j][2],sa[j][1]);
				if(a=sa[j][2]){
					re[2]++;
				}else{
					re[1]++;
				}
			}
			sum+=a;	
		}
		cout<<sum<<endl;
	}
		
	}
	return 0;
}
