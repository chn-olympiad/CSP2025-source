#include<bits/stdc++.h>
using namespace std;
int n, m, p, a[105];
bool cmp(int x, int y){
	return x > y;
}

void shuchu(int k){
	int hang, lie;
	lie = (k - 1) / n + 1;
	cout << lie << " ";
	hang = k % n;
	if(hang == 0)	hang = n;
	if(lie % 2 == 0)	hang = n - hang + 1;
	cout << hang << "\n";
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	p = n * m;
	for(int i = 1;i <= p ;i++){
		scanf("%d", &a[i]);
	}
	int o = a[1];
	sort(a + 1, a + 1 + p, cmp);
	for(int i = 1; i <= p; i++){
		if(a[i] == o)	shuchu(i);
	}
	return 0;
}

