#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n=0, a[10001], m=0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n-3;i++){
		for(int j=2;j<=n-2;j++){
			for(int k=3;k<=n;k++){
				if(a[i]+a[j]+a[k]>=2*a[i]&&a[i]+a[j]+a[k]>=2*a[j]&&a[i]+a[j]+a[k]>=2*a[k]){
					m++;
				}
			}
		}
	}
	for(int o=1;o<=n-4;o++){
	for(int i=2;i<=n-3;i++){
		for(int j=3;j<=n-2;j++){
			for(int k=4;k<=n;k++){
				if(a[i]+a[j]+a[k]+a[o]>=2*a[i]&&a[i]+a[j]+a[k]+a[o]>=2*a[j]&&a[i]+a[j]+a[k]+a[o]>=2*a[k]&&a[i]+a[j]+a[k]+a[o]>=2*a[o]){
					m++;
				}
			}
		}
	}
	}
	for(int p=1;p<=n-5){
	for(int o=2;o<=n-4;o++){
	for(int i=3;i<=n-3;i++){
		for(int j=4;j<=n-2;j++){
			for(int k=5;k<=n;k++){
				if(a[i]+a[j]+a[k]+a[o]+a[p]>=2*a[i]&&a[i]+a[j]+a[k]+a[o]+a[p]>=2*a[j]&&a[i]+a[j]+a[k]+a[o]+a[p]>=2*a[k]&&a[i]+a[j]+a[k]+a[o]+a[p]>=2*a[o]&&a[i]+a[j]+a[k]+a[o]+a[p]>=2*a[p]){
					m++;
				}
			}
		}
	}
	}	
    }
	printf("%d", m);
	return 0;
} 