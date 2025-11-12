#include<bits/stdc++.h>
using namespace std;
int n,m,R,c,r;
int a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			k=i;
			break;
		}
	}
	if(k%n==0){
		c=k/n;
	}else{
		c=k/n+1;
	}
	if(c%2==1){
		if(k%n!=0){
			r=k%n;
		}else{
			r=n;
		}
	}else{
		r=n-k%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
} 
