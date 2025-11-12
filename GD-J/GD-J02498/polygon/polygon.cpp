#include <bits/stdc++.h>
using namespace std;
int a[10000];
int b[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
				int maxn=0,sumn=0;
				for(int k=1;k<=3;k++){
					if(a[k]>=maxn){
						maxn=a[k];
					}
				}
				
				for(int l=i;l<=j;l++){
					sumn+=a[l];
				}
				if(sumn>maxn&&j-i>=3){
					sum++; 
				}
		}
	}
	cout<<sum;
	return 0;
} 
