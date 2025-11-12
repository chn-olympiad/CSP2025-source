#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll C(ll n,ll m){
	ll r=1;
	for(int i=n;i>=n-m+1;i--) r*=i;
	for(int i=m;i>=1;i--) r/=i;
	return r;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; cin>>n>>m;
	if(m>1){
		int x=0;
		for(int i=1;i<=n;i++){
			char c; cin>>c;
			if(c-'0') x++;
		}
		for(int i=1;i<=n;i++){
			int c;cin>>c;
			if(!c) m--;
		} 
		if(m==0) cout<<0;
		cout<<C(x,m);
	} 
	else{
		bool f=false;
		for(int i=1;i<=n;i++){
			char c; cin>>c;
			if(c-'0'){
				f=true;
				break;
			} 
		}
		if(f){
			for(int i=1;i<=n;i++){
				int c;cin>>c;
				if(c) {
					cout<<1;
					return 0;
				}
			}
		}
	}
	return 0;
}


//It was so bad today.
//I wish it will be sunny and bright tomorrow.
//2025.11.1 18:03
