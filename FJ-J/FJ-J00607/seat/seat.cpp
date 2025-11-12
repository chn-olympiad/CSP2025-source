#include<bits/stdc++.h>
using namespace std;
int n,m,s,si;
int a[105];
int c,r; 
bool cmp(int a,int b){
	return a>b;
}
int main( ){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			si=i;
		}
	}
	if(si%n==0) c=si/n;
	else c=si/n+1;
	if(c%2==1){
		r=si-(n*(c-1));
	}
	else{
		r=n-(si-(n*(c-1)))+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

