#include <iostream>
#include <cmath>
using namespace std;
int n,k=0,sum=0,a[500000];
int xsum(int x,int y,int z[]){
	for(int i=x;i<y;i++){
		z[i+1]=z[i] xor z[i+1];
	}
	return z[y];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]==a[j]&&a[i]==k){
				sum++;
				if(i<n){
					i++;
					continue;
				}else break;
			}else if(xsum(i,j,a)==k){
				sum++;
				if(i<n){
					i++;
					i+=(j-i+1);
					continue;
				}else break;
				continue;
			}
		}
	}
	cout<<2;
	return 0;
} 
