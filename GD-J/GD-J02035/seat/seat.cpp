#include<bits/stdc++.h>
using namespace std;
int n,m,x,ii,w,z;
int a[100005];
bool cmp(int x,int y){
	if(x>y){
		return true;
	}
	else{
		return false;
	} 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m-1;i++){
	//	cout<<a[i]<<" "<<x<<endl;
		if(a[i]<x){
			ii=i;
			break;	
		}
	}
//	cout<<ii<<endl;
	w=ii%n;
	if(w==0){
		w=n;
	}
	if(ii>n){
		if(w==n){
			z=ii/n;
		}
		else{
			z=ii/n+1;
		}
	} 
	else{
		z=1;
	}
	if(z%2!=0){
		cout<<z<<" "<<w;
	}
	else{
		cout<<z<<" "<<n-w+1;
	}
	return 0;
}
