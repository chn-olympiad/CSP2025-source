#include<bits/stdc++.h>
using namespace std;
int n, k, t, maxt;
struct f{
	int s;
	bool ff;
	int to;
}a[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		a[i] = {x, 0, 0};
	}
	int sum = -1, o = 2, last = 1;
	for(int i = 1; i <= n + 1; i++){
		if(a[i].ff == 1){
			i = a[i].to;
			t++;
			maxt = max(t, maxt);
			continue;
		}
		if(a[i].s == k){
			t++;
			maxt = max(t, maxt);
			a[i].ff = 1;
			a[i].to = a[i].s;
			sum = -1;
			last = i + 1;
			continue;
		}
		if(sum == -1){
			sum = a[i].s ^ a[i + 1].s;
			i++;
		}
		else
		{
			sum = sum ^ a[i].s;
		}
		if(sum == k){
			t++;
			maxt = max(t, maxt);
			sum = -1;
			a[last].ff = 1;
			a[last].to = i;
			last = i + 1;
		}
		if(i == n){
			if(o == n)	break;
			i = o;
			o++;
			maxt = max(t, maxt);
			t = 0;
		}
	}
	cout << maxt;
}
