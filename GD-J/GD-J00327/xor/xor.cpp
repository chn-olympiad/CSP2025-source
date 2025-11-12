#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 +5;
struct node{
	int l,r;
};
int a[N];
int n,k;
long long pre[N];
vector<node> v;
bool cmp(node a,node b){
	if(a.l != b.l) return a.l < b.l;
	else return a.r < b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	bool flag = true;
	bool flag2 = true;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] != 1) flag = false;
		if(a[i] > 1) flag2 = false;
		pre[i] = pre[i - 1] ^ a[i];
	}
	
	if(flag){
		if(k == 1){
			cout << n;
			return 0;
		}
		else if(k == 0){
			cout << n / 2;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	
	if(flag2){
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++ ) if(a[i] == 1) cnt++;
		if(k == 1){
			cout << cnt;
			return 0;
		}
		else if(k == 0){
			cout << (n - cnt) + (cnt / 2);
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	
	for(int i = 1 ; i <= n ; i++ ){
		for(int j = i ; j <= n ; j++ ){
			if( (pre[j] ^ pre[i - 1]) == k){
				v.push_back({i,j});
				break;
			}
		}
	}
	
	sort(v.begin() , v.end() , cmp);
	
	int lst = 0;
	int cnt = 0;
	for(int i = 0 ; i < v.size() ; i++ ){
		if(i == 0){
			cnt++;
			continue;
		}
		if(v[i].l > v[lst].r){
			lst = i;
			cnt++;
		}
		else if(v[i].l < v[lst].r && v[i].r < v[lst].r){
			lst = i;
		}
	}
	
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
