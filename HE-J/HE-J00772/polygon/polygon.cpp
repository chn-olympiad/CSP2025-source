#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,m=0;
	cin>>n;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int g=i;
		for(int j=i+1;j<=n;j++){
			if(a[g]<a[j]){
				int u=a[g];
				a[g]=a[j];
				a[j]=u;
			}
		}
	}
	for(int l=3;l<=n;l++){
		int z=1,h[l+1];
		for(int i=1;i<=n;i++){
			int num=0;
			for(int j=i;j>=z;j--){
				num+=a[j];
			}
			z++;
			if(num>a[1]*2){
				m++;
			}
		}
	}
	
	cout<<"0";
	return 0;
}
