#include<bits/stdc++.h>
using namespace std;
int sqr(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	freopen;
	int a[100001],n,m,k,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			k=a[i];
		}
	}
	
	sort(a+1,a+(n*m)+1,sqr);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			x=i;
		}
	}
	int l=(x/n)+1,h=(x-1)%n+1;
	if(l%2!=0){
		cout<<l<<' '<<h;
	}
	else if(l%2==0){
		cout<<l<<' '<<n-h+1;
	}
	return 0;
} 
