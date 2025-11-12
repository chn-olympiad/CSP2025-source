#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[100]={0},k=0,z,l,h,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x; 
		if(i==1){
			z=x;
		}
		a[x]++;
	}
	for(int i=100;i>=0;i--){
		if(a[i]!=0){
			k++;
		}
		if(i==z){
			break;
		}
	}
	k-=1;
	if(k%n!=0){
		l=(k/n)+1;
	}else{
		l=k/n;
	}
	s=k-((l-1)*n);
	if(l%2!=0){
		h=s;
	}else{
		h=n-s+1;
	}
	cout<<l<<" "<<h;
	return 0;
}