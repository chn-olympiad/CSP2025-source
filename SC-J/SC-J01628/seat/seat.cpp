#include <bits/stdc++.h> 
#define int long long
#define endl '\n'
using namespace std;
struct S{
	int num, c;
}a[150];
bool cmp(S a, S b){
	return a.c > b.c;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1;i <= n * m;i ++){
		a[i].num = i;
		cin >> a[i].c;
	}
	sort(a+1,a+n*m+1,cmp);
	
	for (int i =1;i <= n * m;i ++){
		if (a[i].num!=1)continue;
		
		int l = (i-1)/n+1;
		int h = i % n;
		if (h == 0)h = n;
		if (l % 2 == 0){
			h = n - h + 1;
		}
		cout << l << " " << h;
		return 0;
	}
	return 0;
}