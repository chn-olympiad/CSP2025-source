#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int mark,g,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>mark;
	for(int i=1;i<=n*m-1;++i){
		cin>>g;
		if(g>mark) ans++;
	}
	k=(ans+n-1)/n;
	cout<<k<<" ";
	if(k%2==0){
		if(ans%n) cout<<m-(ans%n)+1;
		else cout<<1;
	}
	else{
		if(ans%n) cout<<ans%n;
		else cout<<n;
	}
	return 0;
}
