#include<bits/stdc++.h> 
using namespace std;
int a[105];int n,m;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
		if(i==1)q=a[i];
			
			
		
	}
	
	
	int ls=m*n;
	sort(a+1,a+ls+1);
	int wz;
	for(int i=m*n;i>=1;i--){
		if(a[i]==q){
			wz=i;break;
		}
	}
	wz=n*m-wz+1;
	
	int l,r;
	int w=wz%n;
	if(w==0)l=wz/n;
	else{
		l=wz/n+1;
	}
	if(l%2==1){
		if(w==0)r=n;
		else r=w;
	}
	else{
		if(w==0)r=1;
		else r=n-w+1;
	}
	cout<<l<<" "<<r;
	return 0;
}