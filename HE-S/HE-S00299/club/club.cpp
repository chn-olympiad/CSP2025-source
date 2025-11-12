#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int n;
	int a1[10001],a2[10001],a3[10001];
	int max1[10001],sum[10001]={0},sum1,sum2,sum3;
	int a;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a1[j]>a2[j]&&a1[j]>a3[j]){
				sum1++;
			}
			if(a2[j]>a1[j]&&a2[j]>a3[j]){
				sum2++;
			}
			if(a3[j]>a1[j]&&a3[j]>a2[j]){
				sum3++;
		    }
			if(a3[j]>a2[j]){
				swap(a3[j],a2[j]);
			}
			if(a2[j]>a1[j]){
				swap(a2[j],a1[j]);
			}	
			max1[j]=a1[j];
			sum[i]=sum[i]+max1[j];
		}
	}
	for(int z=1;z<=t;z++){
		cout<<sum[z]<<" ";
	}
return 0;
} 
