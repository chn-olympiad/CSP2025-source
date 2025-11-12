#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
namespace Fast{
	inline int fr(){
		int x = 0,f = 1;
		char c = getchar();
		while (c < '0' || c > '9'){
			if (c == '-'){
				f = -1;
			}
			c = getchar();
		}
		while ('0' <= c && c <= '9'){
			x = (x << 1) + (x << 3) + (c ^ 48);
			c = getchar();
		}
		return x * f;
	}
	inline void fw(int x){
		if (x == 0){
			putchar('0');
			return ;
		}
		if (x < 0){
			x = -x;
			putchar('-');
		}
		stack <char> stk;
		while (x){
			stk.push(x % 10 + '0');
			x /= 10;
		}
		while (!stk.empty()){
			putchar(stk.top());
			stk.pop();
		}
	}
	inline void DEBUG(){
		cout<<"CSP-JS rp++; qwq\n";
	}
}

using namespace Fast;
struct Edge{
	int u,v,w;
}e[2000005];

bool cmp(Edge a,Edge b){
	return a.w < b.w;
}

int c[15],t[15][20005],minn[20005],minid[20005],fa[20005];
int Find(int x){
	//cout<<"Find("<<x<<")\n";
	if (fa[x] == x){
		return x;
	}
	fa[x] = Find(fa[x]);
	return fa[x];
}

bool f[20005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n = fr(),m = fr(),k = fr();
	for (int i = 1;i <= m;i++){
		e[i].u = fr(),e[i].v = fr(),e[i].w = fr();
	}
	int idx = m;
	for (int i = 1;i <= k;i++){
		c[i] = fr();
		minn[i] = 1e9 + 7;
		for (int j = 1;j <= n;j++){
			t[i][j] = fr();
			/*
			if (t[i][j] < minn[i]){
				minn[i] = min(minn[i],t[i][j]);
				minid[i] = j;
			}
			*/
			idx++;
			e[idx].u = 10000 + i;
			e[idx].v = j;
			e[idx].w = t[i][j];
		}
		//cout<<i<<' '<<minid[i]<<' '<<minn[i]<<'\n';
	}
	sort(e + 1,e + idx + 1,cmp);
	int maxn = (1LL << k),ans = 1e14 + 5;
	for (int i = 0;i < maxn;i++){
		for (int j = 1;j <= 10000 + k;j++){
			fa[j] = j;
		}
		int sum = 0,cntk = 0;
		for (int j = 1;j <= k;j++){
			f[j] = false;
			if (i & (1LL << (j - 1))){
				sum += c[j];
				//sum += t[j][minn[j]];
				//fa[10000 + j] = minid[j];
				f[j] = true;
				cntk++;
			}
		}
		//cout<<i<<' '<<sum<<'\n';
		if (sum >= ans){
			continue;
		}
		//DEBUG();
		int cnt = 0;
		for (int j = 1;j <= idx;j++){
			//cout<<j<<'\n';
			if (e[j].u > 10000 && !f[e[j].u - 10000]){
				continue;
			}
			int u = e[j].u,v = e[j].v,w = e[j].w;
			int rtu = Find(u),rtv = Find(v);
			//DEBUG();
			if (rtu == rtv){
				continue;
			}
			fa[rtu] = rtv;
			sum += w;
			cnt++;
			//cout<<j<<' '<<sum<<' '<<cnt<<' '<<n + cntk - 1<<'\n';
			if (cnt == n + cntk - 1 || sum >= ans){
				break;
			}
		}
		if (cnt < n + cntk - 1){
			continue;
		}
		//cout<<i<<' '<<sum<<'\n';
		ans = min(ans,sum);
	}
	fw(ans);
	return 0;
}
