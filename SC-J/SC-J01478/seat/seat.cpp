#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==o){
			int j=(n*m)-i+1;
			int l=j/(2*n);
			int h=j%(2*n);
			if(h==0){
				cout<<2*l<<" "<<n;
				return 0;
			}
			if(h>n){
				cout<<2*l+2<<" "<<n-(h-n)+1;
				return 0;
			}else cout<<2*l+1<<" "<<h;
			return 0;
		}
	}
}  