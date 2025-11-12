#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			l=i;
			break;
		}
	}
	if(l%n==0) r=l/n;
	else r=l/n+1;
	cout<<r<<" ";
	if(r%2==0) cout<<n-(l%n)+1;
	else{
		if(l%n==0) cout<<n;
		else cout<<l%n;
	}
	return 0;
}
