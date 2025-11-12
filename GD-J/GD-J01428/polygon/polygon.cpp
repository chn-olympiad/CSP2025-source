#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
  	freopen("polygon.out","w",stdout);
  	int n,a[10001];
  	cin>>n;
  	for(int i=1;i<=n;i++){
  		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]>a[j]){
				int cup;
				cup=a[i];
				a[i]=a[j];
				a[j]=cup;
			}
		}
	}
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
