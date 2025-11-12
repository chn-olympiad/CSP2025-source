#include<bits/stdc++.h>
using namespace std;

int a[105]={0},c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0,sit=1;
	cin>>n>>m;
	ans=n*m;
	cin>>a[1];
	for(int i=2;i<=ans;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			++sit;
		}
	}
	if(sit<=n){
		c=1;
	}else if(sit%n==0){
		c=sit/n;
	}else{
		c=sit/n+1;
	}
	if(c%2==0){
		r=n-(sit-(c-1)*n)+1;
	}else if(c%2==1){
		r=sit-(c-1)*n;
	}
	cout<<c<<" "<<r;
	return 0;
}

