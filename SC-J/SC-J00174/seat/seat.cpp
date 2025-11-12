#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,k,p,c,r;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			p=i;
			break;
		}
	}
	if(p%n==0) c=p/n;
	else c=p/n+1;
	if(p%n==0) r=p%n+n;
	else r=p%n;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}