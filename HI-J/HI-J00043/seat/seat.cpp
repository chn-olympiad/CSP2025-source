#include<bits/stdc++.h>
using namespace std;
int c,r,n,m;
int p[150];
int l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>p[i];
	}
	l=p[1];
	sort(p+1,p+m*n+1);
	int vis=1;
	for(int i=1;i<=n*m;i++){
		if(l==p[i]){
			vis=m*n-i;
			break;
		}
	}
	c=vis/n+1;
	if(c%2==0){
		r=n-vis%n;
	}else{
		r=vis%n+1;
	}
	cout<<c<<" "<<r; 
	return 0; 
}
 
