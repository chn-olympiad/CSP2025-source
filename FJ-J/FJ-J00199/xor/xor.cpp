#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int zl=0,y;
	for(int i=0;i<n;i++){
		int x[i];
		for(int l=0;l<n-i;l++){
			for(int j=i;j<i*2;j++){
				x[0+j-i]=a[j];
			}
			y=x[0];
			for(int j=1;j<i;j++){
				y=(y^x[j]);
			}
			if(y==k){
				zl+=1;
			}
		}
	}
	cout<<zl;
	return 0;
}
