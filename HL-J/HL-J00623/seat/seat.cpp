#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],num,p,c,r;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		num=a[1];
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			p=i;
		}
	}
	c=p;
	r=p;	
	cout<<c<<" "<<r;	
	return 0;
}

