#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],b,c,p,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=n*m-i+1;
			break;
		}
	}
	p=(c-1)/n+1;
	if(p%2==0){
		q=n-(c-1)%n;
	}
	else{
		q=(c-1)%n+1;
	}
	cout<<p<<" "<<q;
	return 0;
}