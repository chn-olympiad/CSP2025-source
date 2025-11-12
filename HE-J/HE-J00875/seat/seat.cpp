#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m,c=0,r=0;
int a[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++){
		scanf("%d",&a[i]);
	}
	int l=a[1];

	for(int i=n*m; i>=1; i--){
		sort(a,a+1);
		if(l==a[i] && i<n){
			c=1,r=i;
		}else if(l==a[i] && i==n){
			c=i/n+1,r=i/m+1;
		}else if(l==a[i] && i>n){
			c=i/n;
			r=i/m+1;
		}else{
			continue;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
