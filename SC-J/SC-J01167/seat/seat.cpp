#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,x;cin>>n>>m;k=n*m;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+k+1);
	int l=lower_bound(a+1,a+k+1,x)-a;
	l=k-l+1;
	int r=(l+n-1)/n;
	if(r%2==0){
		cout<<r<<" "<<n+1-(l-n*(r-1));
	}
	else{
		cout<<r<<" "<<l-n*(r-1);
	} 
	return 0;
}