#include <iostream>
using namespace std;

int n,m,a,cnt;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int aa;cin >> a;
	for (int i=2;i<=n*m;++i){
		cin >> aa;
		if (aa>a) ++cnt;
	} cout << cnt/n+1 << " ";
	if (cnt/n%2==1){
		cnt%=n;
		cout << m-cnt;
	} else {
		cnt%=n;
		cout << 1+cnt;
	} return 0;
}
