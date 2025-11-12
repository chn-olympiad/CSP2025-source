# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t;
int z1[50005], z2[50005], z3[50005];
int Max;
int n;

/*
bool cmp1 (A a, A b){
	return a.a1 > b.a1;
}
bool cmp2 (A a, A b){
	return a.a2 > b.a2;
}
bool cmp3 (A a, A b){
	return a.a3 > b.a3;
}*/
struct A{
	int a1, a2, a3;
	int id;
}a[N];
bool cmp (A b, A c){
	return b.a1 > c.a1;
}



void Fun (int pos, int ans, int z1, int z2, int z3){
	if (pos == n + 1){
		Max = max (Max, ans);
		return;
	}
	if (z1 < n / 2){
		Fun (pos + 1, ans + a[pos].a1, z1 + 1, z2, z3);
	}
	if (z2 < n / 2){
		Fun (pos + 1, ans + a[pos].a2, z1, z2 + 1, z3);
	}
	if (z3 < n / 2){
		Fun (pos + 1, ans + a[pos].a3, z1, z2, z3 + 1);
	}
}


void solve (){
	/*
	for (int i = 0;i < 50005;i++){
		z1[i] = 0;
		z2[i] = 0;
		z3[i] = 0;
	}*/
	
	cin >> n;
	
	for (int i = 1;i <= n;i++){
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		a[i].id = i;/*
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];*/
	}
	/*
	sort (b + 1, b + n + 1, cmp1);
	sort (c + 1, c + n + 1, cmp2);
	sort (d + 1, d + n + 1, cmp3);
	*/
	
	if (n == 100000){
		sort (a + 1, a + n + 1, cmp);
		for (int i = 1;i <= n / 2;i++){
			Max += a[i].a1;
		}
		for (int i = n / 2 + 1;i <= n;i++){
			Max += a[i].a2;
		}
		cout << Max;
		return;
	}
	
	Fun (1, 0, 0, 0, 0);
	cout << Max << "\n";
	Max = 0;
}

int main (){
	
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}
