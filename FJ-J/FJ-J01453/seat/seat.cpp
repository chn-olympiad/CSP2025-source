#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],w=0,b=0,c=1,r=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	w=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
    for(int i=1;i<=n*m;i++){
		if(w==a[i]) {
		b=i; break;}
	}
	c=(b+n-1)/n;
	r=b-((c-1)*n);
	if(c%2==0){
			r=m+1-r; 
	}
	cout<<c<<" "<<r;
	return 0;
} 
