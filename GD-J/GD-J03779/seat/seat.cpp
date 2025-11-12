#include <bits/stdc++.h>
using namespace std;
int n, m, axi[105], a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int zon = n * m;
	for (int i = 1;i <= zon;i++){
		cin >> axi[i];
	}
	int che = axi[1], cnt;
	sort(axi + 1, axi + zon + 1);
	for (int i = 1;i <= zon;i++){
		a[i] = axi[zon - i + 1];
		if(a[i] == che) cnt = i;
	}
	int h, l, pan = cnt % n;
	if(!pan) l = cnt / n;
	else l = cnt / n + 1;
	if(l % 2 == 1){
		if(!pan) h = n;
		else h = pan;
	}
	else{
		if(!pan) h = 1;
		else h = n - pan + 1;
	}
	cout << l << " " << h;
	return 0;
}

