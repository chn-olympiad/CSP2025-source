#include<bits/stdc++.h>
using namespace std;
int n,m,s=1,id;
int up(int x,int y){
	return (x+y-1)/y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>id;
	for(int i=2;i<=n*m;i++){
		int x; cin>>x;
		if(x>id) s++;
	}
	int c=up(s,n);
	if(c&1) cout<<c<<" "<<(s-1)%n+1;
	else cout<<c<<" "<<n-(s-1)%n;
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
7 1 2 3 4 5 6 8 9
*/ 
