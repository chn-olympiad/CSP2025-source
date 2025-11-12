#include<bits/stdc++.h>
using namespace std;
int n,m,p,a,cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>p;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>p) cnt++;
	}
	c=cnt/n+1;
	r=cnt%n+1;
	cout<<c<<' '<<(c%2?r:n-r+1);
	return 0;
}

