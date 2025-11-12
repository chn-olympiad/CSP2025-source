#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,cnt=0;
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		int q;
		cin>>q;
		if(q>r)cnt++;
	}
	if(cnt%m%2){
		cout<<cnt%n<<" "<<cnt%m+1;
	}
	else{
		cout<<n-cnt%n<<" "<<cnt%m+1;
	}
	return 0;
}
