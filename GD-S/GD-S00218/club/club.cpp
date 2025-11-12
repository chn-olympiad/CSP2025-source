#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,y,z,sum,w;
long long a[3][100000];

int main(){
	for(int k=0;k<t;k++){
		if(n%2!=0){
			cout<<0;
		}
		w=n/2;
		for(int i=0;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[j][i];
			}
		}
		for(int i=0;i<n;i++){
			m=max(a[0][i],a[1][i]);
			m=max(m,a[2][i]);
			sum+=m;
			if(m==a[0][i]){
				x++;
			}
			if(m==a[1][i]){
				y++;
			}
			if(m==a[2][i]){
				z++;
			}
		}
		if(x>w||y>w||z>w){
			cout<<0;
		}else{
			cout<<sum;
		}
	}
}
