#include<bits/stdc++.h>
using namespace std;
int a[1145140],r,n,m;
bool cmp(int a,int b){
	return a>b;
}
int findR(int k,int t){
	for(int i=1;i<=t;i++){
		if(a[i]==k){
			return i;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int whereisRnow=findR(r,n*m);
	int j=whereisRnow/(2*m);
	int x=whereisRnow%(2*m);
	int i=x%m;
	if(i==0)i=m;
	int y=x/m;
	if(i==m)y--;
	if(y==1||(i==m&&y==-1))i=m-i+1;
	cout<<j*2+y+1<<' '<<i;
	return 0;
}
