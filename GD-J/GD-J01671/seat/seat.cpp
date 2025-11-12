#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int s=a[1];
	int t;
	for(int i=2;i<=m*n;i++) cin>>a[i];
	sort(a,a+m*n+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			t=n*m+1-i;
			break;
		}
	}
	int r=t%m;
	int c=((t-1)/n)+1;
	if(c%2==0) r=n+1-r;
	if(r==0) r=n;
	cout<<c<<" "<<r;
	return 0;
}
