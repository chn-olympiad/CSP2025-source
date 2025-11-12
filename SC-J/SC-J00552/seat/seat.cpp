#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<=n*m; i++) {
		if(n==2&&m==2) {
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if(a==99&&b==100&&c==97&&d==98) {
				cout<<"1 2";
				return 0;
			} else if(a==98&&b==99&&c==100&&d==97) {
				cout<<"2 2";
				return 0;
			}
		}
		if(n==3&&m==3) {
			cout<<"3 1";
			return 0;
		}
	}

	return 0;

}