#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	if(a[1]+a[2]+a[3]>a[1]*2) cout<<1;
	else cout<<0; 
	return 0;
}