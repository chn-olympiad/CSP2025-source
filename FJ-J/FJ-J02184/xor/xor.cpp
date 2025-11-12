#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
const int MAXN = 5e5 + 5;
struct node{
	int l,r;	
}a[MAXN];
int s[MAXN];
int cnt;
bool cmp(node x,node y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		if(s[i] == k) a[++cnt].l = i,a[cnt].r = i;
	}
	for(int i = 1;i < n;i++){
		for(int j = i + 1;j <= n;j++){
			int xr = s[i];
			for(int k = i + 1;k <= j;k++){
				xr ^= s[k];
			}
			if(xr == k){
				a[++cnt].l = i,a[cnt].r = j;
			}
		}
	}
	sort(a + 1,a + cnt + 1,cmp);
	if(cnt == 0){
		cout << 0 << '\n';
		return 0;	
	}
	int ans = 1;
	bool last = true;
	int pop = 1;
	for(int i = 2;i <= n;i++){
		if(a[i].l > a[i - pop].r){
			last = true;
			ans++;
			pop = 1;
		} else{
			pop++;
		}
	}
	cout << ans << '\n';

	fclose(stdin);
	fclose(stdout);
	return 0;
}

