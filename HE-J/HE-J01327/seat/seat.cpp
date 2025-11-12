#include <bits/stdc++.h>
using namespace std;
int n,m,mubiao;
int mp[10][10];
int a[100];
int b[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	if(n==1  && m==1){
		cout<<1<<" "<<1;
		return 0;
	} 
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++) {
		b[i]=a[n*m-i+1]; 
	}
	
	
	for(int i=1;i<=n*m;i++){
		if(b[i]==num){
			mubiao=i;
		}
	}
	if(n==1 && m==10){
		cout<<mubiao<<" "<<1;
		return 0;
	}
	else if(m==1 && n==10){
		cout<<1<<" "<<mubiao;
		return 0;
	}
	if(mubiao<=n){
		cout<<1<<" "<<mubiao;
		return 0;
	}
	else{
		if(mubiao/2%2){
			cout<<(mubiao/2+mubiao%2)<<" "<<2;
		}
		else{
			cout<<(mubiao/2+mubiao%2)<<" "<<1;
		}
	}
	
	return 0;
} 
