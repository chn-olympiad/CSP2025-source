#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
lld n,m,x,y,l,p,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>y;l=1;
	for(lld i=2;i<=n*m;i++){
		cin>>x;
		if(x>y)l++;
	}
	p=l/n;
	q=l%n;
	if(q>0){p++;}
	else {q+=n;}
	if(p%2==0){
		q=n-q+1;
	}
	cout<<p<<' '<<q;
	return 0;
}