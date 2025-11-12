//GZ_S00147 贵阳中天中学 廖颢云 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,a[N],b[N],c[N],t;
long long sumn;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a+1,a+1+n,greater<int>());
		sort(b+1,b+1+n,greater<int>());
		sort(c+1,c+1+n,greater<int>());
		for(int i = 1;i <= n/2;i++)sumn += a[i];
		for(int i = n/2+1;i <= n / 2 + n / 4;i++)sumn += b[i];
		for(int i = n / 2 + n / 4;i <= n;i++)sumn += c[i];
		cout << sumn << '\n';
		sumn = 0;
	}
	
	return 0;
} 
