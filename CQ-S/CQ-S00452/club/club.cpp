#include<bits/stdc++.h>
using namespace std;
using in = long long;
in n,a[3][100005],r = 0,maxmn = 0,ans = 0;
bool cup(in a,in b){
	return a > b;
}
void A(in f,in y,in b,in c,in ans){
	if(maxmn < ans)
		maxmn = ans;
	if(f > n)
		return;
	if(y <= n / 2 - 1)
		A(f+1,y+1,b,c,ans + a[0][f]);
	if(b <= n / 2 - 1)
		A(f+1,y,b+1,c,ans + a[1][f]);
	if(c <= n / 2 - 1)
		A(f+1,y,b,c+1,ans + a[2][f]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	in t;
	cin >> t;
	while(t --){
		cin >> n;
		for(int i = 1;i <= n;i ++){
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			if(a[1][i] != 0 || a[2][i] != 0)
				r = 1;
		}
		if(r == 0){
			sort(a[0] + 1,a[0] + n + 1,cup);
			for(int i = 1;i <= n/2;i ++)
				ans += a[0][i];
			cout << ans << endl;
		}
		else{
			A(1,0,0,0,0);
			cout << maxmn << endl;
		}
		r = 0,maxmn = 0,ans = 0;
	}
	return 0;
}
