#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int val,id;
	friend bool operator < (Node a,Node b){
		return a.val > b.val;
	}
}a[500006];
int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m; i++)
		cin >> a[i].val,a[i].id = i;
	sort(a+1,a+1+n*m);
	int rak = 0;
	for(int i = 1;i <= n*m; i++)
		if(a[i].id == 1){
			rak = i;
			break;
		}
	int l = (rak-1)/n+1,r = rak-n*(l-1);
	if(l%2 == 1)
		cout << l << " " << r << endl;
	else cout << l << " " << n-r+1 << endl;
	return 0;
}
