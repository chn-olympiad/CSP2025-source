#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,w[N],p[N],num[N],ans = 0;
struct node{ int cost,pos; }a[N];
bool cmp(node x,node y){ 
	if(x.cost == y.cost) return x.pos < y.pos;
	return x.cost < y.cost; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1,x;i <= n;i++){
		cin >> num[i];num[i] ^= num[i-1];
		a[i].cost = num[i],a[i].pos = i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i++) w[i] = a[i].cost,p[i] = a[i].pos;
	
	for(int i = 0;i <= n;i++){
		int x = lower_bound(w+1,w+1+n,(k^num[i])) - w;
		if((num[p[x]] ^ num[i]) != k) continue;
		if(p[x] <= i){
			while(p[x] <= i && (num[p[x]] ^ num[i]) == k) x++;
			if((num[p[x]] ^ num[i]) != k) continue;
		}
		ans++;
		i = p[x]-1;
	}
	cout << ans << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
