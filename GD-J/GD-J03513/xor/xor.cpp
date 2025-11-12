#include<bits/stdc++.h>
using namespace std;

int n, k, a[1000010], d[1000010], ll = 1;
struct node{
	int l, r;
};
node xor1[1000010];
bool cmp(node x, node y){
	return x.l < y.l;  
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	d[1] = a[1];
	for(int i = 2; i <= n; i ++) {
		d[i] = (d[i - 1] ^ a[i]);
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			if((d[j] ^ d[i - 1]) == k){
				xor1[ll].l = i;
				xor1[ll].r = j;
				ll ++;
			}
		}
	} 
	sort(xor1 + 1, xor1 + ll + 1, cmp);
	int ans = 0, cnt = 0;
	if(ll == 2 ){
		cout << 1;
		return 0;
	}
	bool flag = false;
	for(int i = 1; i <= ll; i ++){
		for(int j = i; j < ll; j ++){
			if(xor1[j].r < xor1[j + 1].l) {
				cnt ++;
				flag = true;
			}
			else if(j + 1 != n - j + 1){
				swap(xor1[j + 1], xor1[n - j + 1]);
			}
		}
		ans = max(ans, cnt);
		
		if(cnt < n && flag) i = cnt + 1;flag = false;
		cnt = 0;
	}
	cout << ans;
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
