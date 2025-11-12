#include<bits/stdc++.h>
using namespace std;
int n,m;
	int a[1001];
	int b;
	int c,r;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=0;
	cin>>b;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=1;i<=n*m-1;i++){
		if(b>a[i]){
	    p=1;
	    break;
		} 
		if(b<a[i]){
			p++;
		}
	}
	if(p<=n){
		c=1;
		r=n;
	}
	if(n==1){
		c=p;
		r=1;
	}
	if(m==1){
		c=1;
		r=p;
	}

	cout<<c<<' '<<r;
	return 0;
}
