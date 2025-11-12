#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],r,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	if(r%n==0) l=r/n;
	else l=r/n+1;
	r=r%(2*m);
	if(r>m) h=m*2-r+1;
	else h=r;
	cout<<l<<" "<<h;
	return 0;
}
