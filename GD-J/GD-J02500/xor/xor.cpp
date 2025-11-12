#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans, kk, c[500005];
bool A=true, B=true, C,f[500005];
void dfs(int step, int cnt){
	if (step==k+1){
		ans = max(ans, cnt);
		return ;
	}
	bool flag = true;
	if (c[step]!=-1){
		for (int i=step; i<=c[step]; i++){
			if (f[i]==true){
				flag = false;
				break;
			}
		}
		if (flag==true){
			for (int i=step; i<=c[step]; i++){
				f[i] = true;
			}
			dfs(step+1, cnt+1);
		}
		if (flag==true) for (int i=step; i<=c[step]; i++) f[i] = false;
		dfs(step+1, cnt);
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		if (a[i]!=1) A = false;
		if (a[i]>1) B = false;
	}
	if (k==0 && A==true){
		cout << n/2;
		return 0;
	}
	if (k<=1 && B==true){
		int sum = 0, s1 = 0, s0 = 0, ss = 0;
		for (int i=1; i<=n; i++){
			if (a[i]==1) s1 ++;
			else s0 ++;
		}
		for (int i=1; i<n; i++){
			if (a[i]==1 && a[i+1]==1){
				sum ++;
				a[i] = a[i+1] = -1;
			}
		}
		if (k==0){
			for (int i=1; i<=n; i++){
				if (a[i]==1){
					bool f = false;
					i ++;
					while (a[i]!=1 && i<=n){
						if (a[i]==-1) f = true;
						i ++;
					}
					if (a[i]==1 && !f) ss ++;
					i ++;
				}
			}
			cout << max(ss+sum, s0+sum);
			return 0;
		} else {
			cout << s1;
			return 0;
		}
	}
	for (int i=1; i<=n; i++){
		if (a[i]==k){
			c[++k] = i;
			continue ;
		}
		int id = i+1, sum = a[i];
		while(id<=n && sum^a[id]!=k) id ++;
		if (id>=1 && id<=n) c[++kk] = id;
		else c[++kk] = -1;
	}
	dfs(1, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
