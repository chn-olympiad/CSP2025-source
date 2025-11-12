#include<bits/stdc++.h>
using namespace std;
int bn1[10005]={};
int bn2[10005]={};
int bn3[10005]={};
int main(){
	freopen("club1.in","in",stdin);
	freopen("club1.out","out",stdout);
	int b;
	cin>>b;
	for(int i=0;i<b;i++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>bn1[i]>>bn2[i]>>bn3[i];
		}
		int sum=0;
		int sum1=0;
		for(int j=0;j<(n/2);j++){
			for(int i=0;i<n;i++){
				if(bn1[sum]<bn1[i]){
					sum=i;
				}	
			}
			sum1=bn1[sum]+sum1;
			bn1[sum]=0;
			bn2[sum]=0;
			bn3[sum]=0;	
		}
		sum=0;
		for(int j=0;j<(n/2);j++){
			for(int i=0;i<n;i++){
				if(bn2[sum]<bn2[i]){
					sum=i;
				}	
			}
			sum1=bn2[sum]+sum1;
			bn2[sum]=0;
			bn3[sum]=0;	
		}
		sum=0;
		for(int j=0;j<(n);j++){
			for(int i=0;i<n;i++){
				if(bn3[sum]<bn3[i]){
					sum=i;
				}	
			}
			sum1=bn3[sum]+sum1;
		}
		cout<<sum1<<endl;
	}
	return 0;
} 
