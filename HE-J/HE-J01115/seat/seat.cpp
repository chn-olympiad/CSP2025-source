#include<iostream>
#include<algorithm>
#include<cstdio>
#define var long long
using namespace std;
var n,m,a[200]; 
int cmp(var a,var b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	var mn = n*m;
	for(var i=1;i<=n*m;i++){
		cin>>a[i];
	}
	var a1 = a[1];
	sort(a+1,a+n*m+1,cmp);
	var p;
	//cout<<a1<<endl;
	for(var i=1;i<=n*m;i++){
		//cout<<a[i]<<' ';
		if(a1==a[i]){
			p = i; break;
		}
	}
	var m0 = p%n==0?p/n:p/n+1;
	var d=p%n,n0;
	if(d!=0){
		n0 = m0%2==0?n-d+1:d;
	}
	else{
		n0 = m0%2==0?1:n;
	}
		
	cout<<m0<<' '<<n0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
