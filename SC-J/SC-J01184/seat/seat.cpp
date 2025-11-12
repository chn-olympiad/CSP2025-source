#include<bits/stdc++.h>
using namespace std;
const int N = 14;
typedef long long ll;
int n,m,e,a[N];

void solve(){
	cin >> n >> m;
	cin >> e;
	a[1]=e;
	for(int i=2;i<=n*m;i++) cin >> a[i];
	sort(a+1,a+1+n*m);
	int f=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[f--]==e){
					cout << i << ' ' << j << '\n';
					return;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[f--]==e){
					cout << i << ' ' << j << '\n';
					return;
				}
			}
		}
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}