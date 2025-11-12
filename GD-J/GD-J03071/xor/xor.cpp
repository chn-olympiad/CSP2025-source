//wonder:60pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
struct point{
	int l,r;
}b[1000005];
int f[1000005];
bool cmp(point a,point b){
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
void work(){
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int tot = 0;
	for(int i = 1;i <= n;i++){
		int sum = 0;
		for(int j = i;j <= n;j++){
			sum = sum ^ a[j];
			if(sum == k){
				b[++tot] = (point){i,j};
			}
		}
	}
	sort(b+1,b+1+tot,cmp);
	int ans = 0;
	for(int i = 1;i <= tot;i++){
		f[i] = 1;
	}
	for(int i = 1;i <= tot;i++){
		for(int j = 1;j <= i;j++){
			if(b[j].r >= b[i].l) continue;
			f[i] = max(f[i],f[j] + 1);
		}
		ans = max(ans,f[i]);
	}
	cout << ans;
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int t = 1;
//	cin >> t;
	while(t--){
		work();
		if(t) cout << endl;
	}
}
