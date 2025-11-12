#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,k,da,v,s,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>k;
		if(i==0)v=k;
		a[k]++;
	}
	for(int i=100;i>=v;i--){
		if(a[i]==1){
			da++;
		}
	}
	
	s=int(da/n);
	y=da%n;
	
//	cout<<s<<" "<<y<<endl;
	if(y==0){
		if(int(s)%2==1){
			cout<<s<<" "<<n<<endl;
		}
		else {
			cout<<s<<" "<<1<<endl;
		}
	}
	else {
		if(s%2==1){
			cout<<s+1<<" "<<n-y+1;
		}
		else {
			cout<<s+1<<" "<<y<<endl;
		}
	}
	return 0;
}