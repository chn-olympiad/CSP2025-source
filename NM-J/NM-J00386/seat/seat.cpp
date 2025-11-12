#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int rf(int e[],int a,int r){
	int l=1,mid;
	for(int i=1;i<=100;i++){
		 mid=(l+r)/2;		
		if(e[mid]==a)return mid;
		else if(e[mid]>a)l=mid;
		else r=mid;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,c=0,b=0,e=0,a[110]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m,cmp);
	b=rf(a,c,n*m);
	e=(b+n-1)/n;
	cout<<e<<' ';
	if(e%2!=0){
		if(b%n==0) cout<<n;
		else cout<<b%n;
	}
	else{
		if(b%n==0) cout<<1;
		else cout<<1+n-(b%n);	
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

