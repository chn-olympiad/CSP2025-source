#include<bits/stdc++.h>
using namespace std;

int m,n,a[105],aa,w,l,h;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	aa=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aa){
			w=n*m+1-i;
			break;
		}
	}
	l=w/m+1;
	h=w%m;
	if(h==0) l--,h=m;
	if(l%2==0) h=n+1-h;
	cout<<l<<" "<<h;
	return 0;
}
