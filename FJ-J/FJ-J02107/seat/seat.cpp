#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,s=0;cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			s=n*m-i+1;
			break;
		}
	}
	int c=0,r=0;
	if(s%n!=0) c=s/n+1;
	else c=s/n;
	if(c%2!=0) r=s-(c-1)*n;
	else r=n-(s-(c-1)*n)+1;
	cout<<c<<" "<<r;
	return 0;
}

