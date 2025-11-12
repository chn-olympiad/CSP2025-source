#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a,id;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	id=1;
	for(int i=2,x;i<=n*m;i++){
		cin>>x;
		if(x>a) id++;
	}
	int x=id/n,y=id%n;
	if(y) cout<<x+1<<' ';
	else cout<<x<<' ';
	if(id<=n) cout<<id;
	else if(y==0){
		if(x&1) cout<<n;
		else cout<<1;
	}else if((x+1)&1){
		if(y==0) cout<<n;
		else cout<<y;
	}else{
		if(y==0) cout<<n;
		else cout<<n-y+1;
	}
	return 0;
}
