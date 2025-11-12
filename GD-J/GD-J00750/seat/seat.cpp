#include<bits/stdc++.h>
using namespace std;
int a[100000],d;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]) r=i;
	}
	int s=r;
	for(int i=1;i<=100;i++){
		if(m*i>=s){
			cout<<i<<' ';
			d=i;
			break;
		}
	}
	if(d%2!=0) cout<<r-m*(d-1);
	else cout<<m-(r-m*(d-1))+1;
	return 0;
}
