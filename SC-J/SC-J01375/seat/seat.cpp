#include<bits/stdc++.h>
using namespace std;
int f(int a,int b){
	if(a%b==0) return b;
	else return a%b;
}
int main(){
	int a[1000],c,k,n=1;
	cin>>c>>k;
	for(int i=1;i<=c*k;i++) cin>>a[i];
	for(int i=1;i<=c*k;i++) if(a[i]>a[1]) n++;
	cout<<n/k<<" "<<f(n,k);
	return 0;
}