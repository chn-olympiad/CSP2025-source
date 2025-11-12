#include<bits/stdc++.h>
using namespace std;
int n,nadd=0,a[5001]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygin.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=n+1;j>i;j--){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				if(a[i]+a[j]+a[z]>2*a[z]){
					nadd+=1;
				}
			}
		}
	}
	cout<<nadd;
	return 0;
}
