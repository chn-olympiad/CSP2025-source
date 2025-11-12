#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101],t,ti,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
			if(a[j]==t)ti=i;
		}
	}
	c=(ti/n)+1;
	r=ti%n;
	if(c%2==0){
		if(r==0)r=n;
		else r=n-r+1;
	}
	cout<<c<<" "<<r;

}
