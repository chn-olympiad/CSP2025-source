#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int binary_Search(int a[N],int l,int r,int x){
	while(l<=r){
		int mid = (l+r)/2;
		;if(a[mid]==x) return mid;
		if(a[mid]< x) r = mid-1;
		if(a[mid]> x) l = mid+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[N];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x = a[1];
	sort(a+1,a+n*m+1,[](int x,int y){return x>y;});
	int nx = binary_Search(a,1,n*m,x);
	cout<<(nx-1)/n+1;
	if(((nx-1)/n+1)%2==1) {
		if(nx%n==0) cout<<" "<<n;
		else cout<<" "<<nx%n;
	}
	else cout<<" "<<m-(nx)%n+1;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
