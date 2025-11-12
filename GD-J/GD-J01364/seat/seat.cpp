#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,t,s=1,k,x,y;
	cin>>n>>m>>t;
	for(int i=2;i<=n*m;i++){
		cin>>k;
		if(k>t)s++;
	}
	x=(s+n-1)/n;
	s%=n;
	if(x%2==1){
		y=s+(s==0)*n;
	}
	else{
		y=n-s+1-(s==0)*n;
	}
	cout<<x<<" "<<y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0; 
}
