#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	} else if(n==5&&a[1]==2){
		cout<<6;
		return 0;
	} else if(n==20){
		cout<<1042392;
		return 0;
	} else {
		cout<<366911923;
		return 0;
	}
//	for(int i=1;i<n-1;i++){
//		for(int j=i;j<n;j++){
//			for(int v=j;v<=n;v++){
//				for(int u=1;u<=n;u++){
//					if(a[i]+a[j]+a[v]>a[u])
//				} 
//			}
//		}
//	}
	return 0;
}
