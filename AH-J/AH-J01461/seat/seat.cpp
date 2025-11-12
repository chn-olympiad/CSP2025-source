#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,t=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1],h=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		++t;
		if(a[i]==p){
			h=t;
			break;
		}
	}
	long long l,r;
	if(h%n==0) l=h/n;
	else l=h/n+1;
	r=h-n*(l-1);
	if(r>n) r-=n;
	if(l%2==0){
		r=n-r+1;
	}
	cout<<l<<" "<<r;
	return 0;
}
