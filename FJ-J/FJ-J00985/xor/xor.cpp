#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N],n,k,l,res,top;
int b[N];
int f,f1;
struct Node{
	int l,r;
}cnt[N];
bool cmp(Node a,Node b){
	return a.r < b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] != 1 && a[i] != 0){
			f1 = -1;
			f = -1;
			break;
		}
		if(a[i] == 1){
			f1 = 1;
		}else if(a[i] == 0){
			f = 1;
		}else{
			f1 = f = -1;
			break;
		}
	}
	if(f1 == 1 && f == 0){
		cout << n / 2;
		return 0;
	}
	if(f1 == 1 && f == 1){
		int ans = 0;
		if(k == 0){
			for(int i = 1; i <= n; i++){
				if(a[i] == 0) ans++;
				if(a[i] && a[i + 1]) ans++;
			}
		}else{
			for(int i = 1; i <= n; i++){
				if(a[i] == 1) ans++;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int res = 0;
		for(int j = i - 1; j >= 1; j--){
			res ^= a[j];
			if(res == k){
				cnt[++top] = {j,i};
				break;
			}
		}
	}
	sort(cnt + 1,cnt + 1 + top,cmp);
	int ans = 0,mr = -1;
	for(int i = 1; i <= top; i++){
		if(mr <= cnt[i].l){
			mr = cnt[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
