#include<bits/stdc++.h>
using namespace std;
int a[101][101],b[100001];
bool cmp(int x,int y){
	if(x>y)return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,r,k=1,v;
	cin>>n>>m;
	cin>>b[1];
	v=b[1];
	for(int i=2;i<=m*n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	while(b[k]!=v){
		k++;
	}
	c=k/n+1;
	r=k%n;
	if(r==0){
		r=n;
		c--;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<' '<<r;
	return 0;
}