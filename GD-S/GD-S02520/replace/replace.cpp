#include<bits/stdc++.h>

using namespace std;

int n,q;
string a[200005],b[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	while(q--){
		int ans = 0,xn,yn;
		string x,y,xx[5000005],yy[5000005];
		cin >> x >> y;
		xn = x.size();
		yn = y.size();
		x = '7' + x;
		y = '7' + y;
		if(xn != yn){
			cout << 0 << endl;
			continue;
		}
		xx[0] = "";
		yy[xn + 1] = "";
		for(int i = 1;i <= xn;i++){
			xx[i] = xx[i - 1] + x[i];
		}
		for(int i = xn;i >= 1;i--){
			yy[i] = yy[i + 1] + x[i];
		}
		for(int l = 1;l <= x.size();l++){
			for(int r = l;r <= x.size();r++){
				for(int i = 1;i <= n;i++){
					if(a[i].size() != r - l + 1)continue;
					if('7' + xx[l - 1] + a[i] + yy[r + 1] == x && '7' + xx[l - 1] + b[i] + yy[r + 1] == y){
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
