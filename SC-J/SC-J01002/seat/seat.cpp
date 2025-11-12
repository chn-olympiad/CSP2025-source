#include<bits/stdc++.h>
using namespace std;
int  a[1010],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+1+n*m);
	for(int i = 1; i <= n*m;i++){
	for(int j = 1; j <= i; j++){
		if(a[j]<a[i]){
			swap(a[i],a[j]);
		}
	}
	}
	int x=1,y=0,z;
	for(int i = n*m; i >= 1; i--){
		if(a[i]==k){
			z=i;
		}
	}
	int m2=m*2;
	if(z<m2){
		if(z<=m){
			cout<<1<<" "<<z;
		}
		else{
			cout<<2<<" "<<m-z%m+1;
		}
	}
	if(z==m2){
		cout<<2<<" "<<1;
	} 
	if(z>m2){
		cout<<z%m+z/m<<" "<<z%m2;
	}
	return 0;
}