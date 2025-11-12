#include<bits/stdc++.h>
using namespace std;
int n,m,r,rr;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int up(int x,int y){
	if(x%y==0){
		return x/y;
	}else{
		return x/y+1;
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
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			rr=i;
			break;
		}
	}
	int u=up(rr,n);
	cout<<u<<" ";
	if(u&1){
		cout<<rr-(u-1)*n;
	}else{
		cout<<n-(rr-(u-1)*n)+1;
	}
	return 0;
}
