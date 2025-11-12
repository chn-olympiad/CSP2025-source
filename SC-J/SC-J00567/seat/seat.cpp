#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll n,m,ans;
ll a[110];

void read(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
}
void solve(){
	for(int i=1,p=1;i<=n;i++){
		if(i%2) {
			for(int j=1;j<=n;j++){
				if(ans==a[p]) {
					cout<<i<<" "<<j<<'\n';
					return;
				}
				p++;
			}
		}
		else{
			for(int j=n;j>0;j--){
				if(ans==a[p]) {
					cout<<i<<" "<<j<<'\n';
					return;
				}
				p++;
			}
		}
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ont","w",stdout);
	read();
	solve();
	return 0;
}