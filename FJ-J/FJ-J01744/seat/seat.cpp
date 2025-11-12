#include <bits/stdc++.h>
using namespace std;

int n,m,c,r,k;
int a[110];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k)k=i;
	}
	
	if(k%n){
		c=k/n+1;
		if(c%2)r=k%n;
		else r=n-k%n+1;
	}else{
		c=k/n;
		if(c%2) r=n;
		else r=1;
	}
	
	cout<<c<<" "<<r; 
	return 0;
} 
