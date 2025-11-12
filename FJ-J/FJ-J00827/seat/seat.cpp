#include<bits/stdc++.h>
using namespace std;
int n,m,num,id,c,r,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num) id=i;
	}
	c=id/n;
	if(id%n) c++;
	if(id%n==0){
		if(c&1) r=n;
		else r=1;
	}
	else{
		if(c&1) r=id%n;
		else r=n-id%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
