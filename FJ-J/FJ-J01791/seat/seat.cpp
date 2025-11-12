#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freoepn("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	if(R%n==0) c=R/n;
	else c=R/n+1;
	cout<<c<<' ';
	if(c%2==1) cout<<R-(c-1)*n;
	else cout<<n-(R-(c-1)*n)+1;
	return 0;
}
