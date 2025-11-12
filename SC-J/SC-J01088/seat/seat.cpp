#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,a,s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;++i){
		cin>>s;
		if(s>a) ++k;
	}
	if(k%n>0){
		cout<<k/n+1<<" ";
		if((k/n+1)%2==1) cout<<k%n;
		else cout<<n-k%n+1;
	}
	else{
		cout<<k/n<<" ";
		if((k/n)%2==1) cout<<n;
		else cout<<1;
	}
	return 0;
}