#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1e2;
int n,k,a[N],pre[N],idx,cnt,flag[N];
struct Node{
	int l,r;
}ans[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = pre[i-1] ^ a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j >= 1;j--){
			if( int( pre[i] ^ pre[j-1] ) == k ){
				idx++;
				ans[idx].l = j,ans[idx].r = i;
			}
		}
	}
	for(int i = 1;i <= idx;i++){
		for(int j = ans[i].l;j <= ans[i].r;i++) flag[j]++;
	}
	for(int i = 1;i <= idx;i++){
		bool found = 0;
		for(int j = ans[i].l;j <= ans[i].r;j++){
			if( flag[j] > 1 ){
				found = 1;
				break;
			}
		}
		if( !found || ( ans[i].l == ans[i].r && flag[ans[i].l] == 2 && flag[ans[i].r] == 2 ) ) cnt++;
	}
	cout << cnt;
	return 0;
}