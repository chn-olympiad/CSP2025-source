#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,x,si=1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){cin>>x;if(x>a)si++;}
	if(((si-1)/n)%2){
		cout<<(si-1)/n+1<<' '<<n-(si-1)%n;
	}
	else{
		cout<<(si-1)/n+1<<' '<<(si-1)%n+1;
	}
	return 0;
}