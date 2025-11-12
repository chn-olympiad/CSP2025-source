#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int i,j,k,l,o;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>2*a[k]){
					ans++;
				}
				if(n>=4){
					for(l=k+1;l<n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
						}
					}
					if(n>=5){
						
					for(o=l+1;o<n;o++){
						
						if(a[i]+a[j]+a[k]+a[l]+a[o]>2*a[o]){
							ans++;
							
						}
					}
				}
				}
				
			}
		}
	}
	cout<<ans;
	return 0;
}
