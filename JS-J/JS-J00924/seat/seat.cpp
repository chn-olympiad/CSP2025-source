#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int se[110], n, m;
int nmm[11][11];

bool cmp(int a, int b){return a>b;}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x; cin >> x; se[1]=x;
	for (int i=2;i<=n*m;++i) cin >> se[i];
	sort(se+1,se+n*m+1,cmp);
	int see=0;
	for (int j=1;j<=m;++j){
		if (j&1){
			for (int i=1; i<=n; ++i){
				see++;
				nmm[i][j]=se[see];
				if (nmm[i][j] == x){
					cout << j << ' ' << i;
					return 0;
				}
			}
			continue;
		}
		for (int i=n; i; --i){
			see++;
			nmm[i][j]=se[see];
			if (nmm[i][j] == x){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}
