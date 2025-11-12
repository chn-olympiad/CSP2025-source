#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],p=1,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	for(int i=2;i<=n*m;i++){
		if(s[1]<=s[i]) p++;
	}
	c=ceil(p*1.0/n);
	cout<<c<<' ';
	if(c==1){
		cout<<p;
		return 0;
	}
	if(c%2==1){
		if(p%n==0) cout<<n;
		else cout<<p%n;
	}
	else{
		cout<<n-p%n+1;
	}

	return 0;
}