#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int n;
int cnta = 0, cntb = 0, cntc = 0;

struct node{
	int a, b, c;
	int m;
}x[MAXN];

bool cmp(const node x, const node y){
	return x.m > y.m;
}

void solve(){
	int ans = 0;
	cnta = 0, cntb = 0, cntc = 0;
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &x[i].a, &x[i].b, &x[i].c);
		x[i].m = max(x[i].a, max(x[i].b, x[i].c));
	}
	
	sort(x+1, x+n+1, cmp);
	
	for(int i = 1; i <= n; i++){
		if(x[i].m == x[i].a){
			cnta++;
			if(cnta > n/2) continue;
			ans += x[i].m;
			//cout << x[i].m << endl;
			continue;
		}
		if(x[i].m == x[i].b){
			cntb++;
			if(cntb > n/2) continue;
			ans += x[i].m;
			//cout << x[i].m << endl;
			continue;
		}
		if(x[i].m == x[i].c){
			cntc++;
			if(cntb > n/2) continue;
			ans += x[i].m;
			//cout << x[i].m << endl;
			continue;
		}
	}
	
	printf("%d\n", ans);
	
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while(T--) solve();
	
	return 0;
}
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响
//我听见了，【强运】的回响