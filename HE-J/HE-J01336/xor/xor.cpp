#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,k,a[N];
int ans;
struct node{
	int l,r;
}x[N];
int g = 1;
bool cmp(node x,node y){
	return x.l < y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int h = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++){
			if(i == j) h = a[i];
			else
				for(int u = i; u <= j; u++)
					h = h ^ a[u];
			if(h == k) 
			{
				x[g].l = i;
				x[g].r = j;
				ans++;
				g++;
			}
			h = 0;
		}
	}
	g--;
	int sum = 1;
	int maxn = 0;
	sort(x + 1,x + g + 1,cmp);
	for(int i = 1; i < g; i++){
		int o = i;
		for(int j = i + 1; j <= g; j++)
		{
			if(x[j].l <= x[o].r) continue;
			sum++; 
			o = j;
		}
		maxn = max(sum,maxn);
		sum = 1;
	}
	cout << maxn;
	return 0;
}
