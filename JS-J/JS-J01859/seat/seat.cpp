#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,h,l,g=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a){
			g++;
		}
	}
	h=(g-1)/n+1;
	l=g%m;
	if(l==0){
		l=n;
	}
	if(h%2==0){
		l=m-l+1;
	}
	cout<<h<<' '<<l<<'\n';
	return 0;
}
