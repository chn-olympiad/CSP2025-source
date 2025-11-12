#include<bits/stdc++.h>
using namespace std;
int n,m,w,k=0,c=0,r=0;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=w;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+w+1,greater<int>());
	for(int i=1;i<=w;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	if(k%n==0){
		r=n;
		c=k/n;
	}else{
		c=k/n+1;
		if(c%2==0){
			r=n-k%n+1;	
		}else{
			r=k%n;
		}	
	}
	cout<<c<<' '<<r;
	return 0;
} 
