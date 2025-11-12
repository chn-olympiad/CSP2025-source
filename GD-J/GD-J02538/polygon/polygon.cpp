#include <bits/stdc++.h>
using namespace std;
int n,w[5010],x[5010],s;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	x[0]=w[0];
	for(int i=1;i<n;i++){
		x[i]=x[i-1]+w[i];
	}
	sort(w,w+n);
	for(int i=3;i<=n;i++){
		int m=1,k=1;
		for(int j=0;j<i;j++){
			m*=n-j;
			k*=j+1;
		}
		s+=m/k;
	}
	cout<<s; 
}
