#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int l=(i-1)/n+1;
			cout<<l<<" ";
			if(l%2==1) cout<<i-(l-1)*n;
			else cout<<n-(i-(l-1)*n)+1;
		}
	}
	return 0;
}
