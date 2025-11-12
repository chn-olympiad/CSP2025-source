#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001][500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int o=0;
			for(int k=1;k<=i;k++){
				o^=a[1][k];
			}
			a[i][j]=o;
		}
	}
	
	return 0;
}
