#include <bits/stdc++.h>
using namespace std;
int n,m;
struct ss{
	int val,i;
};
ss a[105];
bool cmp(ss x,ss y){
	return x.val > y.val;
}
int l = 1,r = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[(i-1)*m+j].val;
			a[(i-1)*m+j].i = (i-1)*m+j;
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++){
		if(l%2){
			if(r+1<=n) r++;
			else l++;
		}else{
			if(r-1>=1) r--;
			else l++;
		}
		if(a[i].i==1){
			cout << l << ' ' << r;
			return 0;
		}
	}
	return 0;
}