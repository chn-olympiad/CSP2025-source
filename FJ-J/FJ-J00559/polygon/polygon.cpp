#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int num=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>a[k]*2) num++;
				for(int t=k+1;t<n;t++){
					if(a[i]+a[j]+a[k]+a[t]>a[t]*2) num++;
					for(int p=t+1;p<n;p++){
						if(a[i]+a[j]+a[k]+a[t]+a[p]>a[p]*2) num++;
						for(int g=p+1;g<n;g++){
							if(a[i]+a[j]+a[k]+a[t]+a[p]+a[g]>a[g]*2) num++;
							for(int d=g+1;d<n;d++){
							if(a[i]+a[j]+a[k]+a[t]+a[p]+a[g]+a[d]>a[d]*2) num++;
							}
						}
					}
				}
			}
		}
	}
	cout<<num;
	return 0;
} 
