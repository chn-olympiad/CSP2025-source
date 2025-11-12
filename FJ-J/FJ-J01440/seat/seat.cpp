#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[10001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+1+n*m,cmp);
	double zw=0;
	for(int i=1;i<=n*m;i++){
		if(a[i] == w)zw=i;
	}
	int n_zw=ceil(zw*1.0/n*1.0);
	cout<<n_zw<<" ";
	int x_zw=0;
	if(zw*1.0/n*1.0 != int(zw*1.0/n*1.0)){
		x_zw=int(zw*1.0/n*1.0);
	}
	else{
		x_zw=n_zw-1;
	}
	
	int d_aw=(int)zw%n;
	if(n_zw%2 == 1){
		cout<<zw-(x_zw*n)<<endl;
	}
	if(n_zw%2 == 0){
		cout<<n-zw+(x_zw*n)+1<<endl;
	}
	return 0;
}
