#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],z1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int z=a[i];
			for(int k=i+1;k<=j;k++){
				z^=a[k];
			}
			if(z==m){
				z1++;
				i=j+1;
				j=i-1;
			}
		}
	}
	cout<<z1;
	return 0;
}
