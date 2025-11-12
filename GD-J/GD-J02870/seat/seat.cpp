#include <bits/stdc++.h>
using namespace std;
int n,m,old,k;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	old=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--) {
		if(a[i]==old){
			k=n*m-i+1;
			break;
		}
	}
	int c=0, r=0,sq=n*m;
	if(k%n==0) c=k/n;
	else c=k/n+1;
	
	if(k==sq) r=n;
	else if(c%2==0) r=n-(k%n)+1;
	else if(k<=n) r=k;
	else r=k%n;
	cout<<c<<" "<<r;
	return 0;
} 
