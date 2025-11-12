#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,a[1005],b[1005][1005],sum[1005]={0};
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			for(int k=1;k<=3;k++){
				cin>>b[j][k];
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=a[i];j++){
			for(int k=1;k<=3;k++){
				if(b[j][k]){
					sum[i]++;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		if(sum[i]%2==0&&sum[i]%3==0){
			if(i%2!=0){
				cout<<sum[i]*3<<endl;
			}else{
				cout<<sum[i]-2<<endl;
			}
		}else{
			cout<<pow(sum[i],2)-sqrt(sum[i])-1<<endl; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
