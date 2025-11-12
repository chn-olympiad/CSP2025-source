#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
unsigned long long u[5000005][2], po2[5000005];
long long k[5000005][2], po1[5000005];
int n, q, cnt, ans[200005], sum;
string s1, s2;
struct node{
	unsigned long long x, y1, y2, z;
	long long a, b1, b2, c;
	int l, r, len, si;
	/*bool operator < (const node &x)const{
		if(len != x.len)return len < x.len;
		if(y1 != x.y1)return y1 < x.y1;
		if(y2 != x.y2)return y2 < x.y2;
		if(x != x.x)return x < x.x;
		return z < x.z;
	}*/
}d[400005];
void init(string a, string b, int k, int id){
	cnt++;
	int l = -1, r = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i]){
			r = i;
			if(l == -1)l = i;
		}
	}
	d[cnt].si = a.size();
	d[cnt].l = l;
	d[cnt].r = r;
	d[cnt].len = r - l + 1;
	unsigned long long x = 0;
	long long y = 0;
	for(int i = 0; i < l; i++){
		x *= 27, y *= 27;
		y %= p;
		x += (a[i] - 'a' + 1);
		y += (a[i] - 'a' + 1);
		y %= p;
	}
	d[cnt].a = y, d[cnt].x = x;
	
	x = 0, y = 0;
	for(int i = r + 1; i < a.size(); i++){
		x *= 27, y *= 27;
		y %= p;
		x += (a[i] - 'a' + 1);
		y += (a[i] - 'a' + 1);
		y %= p;
	}
	d[cnt].c = y, d[cnt].z = x;
	
	x = 0, y = 0;
	unsigned long long xx = 0;
	long long yy = 0;
	for(int i = l; i < r; i++){
		x *= 27, y *= 27;
		y %= p;
		x += (a[i] - 'a' + 1);
		y += (a[i] - 'a' + 1);
		y %= p;
		
		xx *= 27, yy *= 27;
		yy %= p;
		xx += (b[i] - 'a' + 1);
		yy += (b[i] - 'a' + 1);
		yy %= p;
	}
	d[cnt].b1 = y, d[cnt].y1 = x;
	d[cnt].b2 = yy, d[cnt].y2 = xx;
}
bool ck(int i, int l, int r, long long x, unsigned long long y){
	if((k[r][i] - (k[l - 1][i] * po1[r - l]) % p + p) % p == x){
		if(u[r][i] - (u[l - 1][i] * po1[r - l]) == y){
			return true;
		}
	}
}
void find(string a, string b){
	int l = -1, r = 0, ans = 0;
	for(int i = 0; i < a.size(); i++){
		if(i == 0){
			po1[0] = 27;
			po2[0] = 27;
			k[0][0] = (a[0] - 'a') + 1;
			u[0][0] = (a[0] - 'a') + 1;
			k[0][1] = (b[0] - 'a') + 1;
			u[0][1] = (b[0] - 'a') + 1;
		}else{
			po1[i] = (po1[i - 1] * 27) % p;
			po2[i] = (po2[i - 1] * 27);
			k[i][0] = k[i - 1][0] * 27;
			k[i][0] %= p;
			u[i][0] = u[i - 1][0] * 27;
			k[i][1] = k[i - 1][1] * 27;
			k[i][1] %= p;
			u[i][1] = u[i - 1][1] * 27;
			k[i][0] += (a[i] - 'a') + 1;
			u[i][0] += (a[i] - 'a') + 1;
			k[i][1] += (b[i] - 'a') + 1;
			u[i][1] += (b[i] - 'a') + 1;
		}
		if(a[i] != b[i]){
			r = i;
			if(l == -1)l = i;
		}
	}
	for(int i = 1; i <= n; i++){
		if(d[i].len != r - l + 1)continue;
		if(ck(0, l, r, d[i].b1, d[i].y1) && ck(1, l, r, d[i].b2, d[i].y2)){
			int ll = l - (d[i].l - 1), rr = r + d[i].si - d[i].r;
			if(ck(0, ll, l - 1, d[i].a, d[i].x)){
				if(ck(1, r + 1, rr, d[i].c, d[i].z))ans++;
			}
		}
	}
	printf("%d\n", ans);
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		init(s1, s2, 1, i);
	}
	for(int i = 1; i <= q; i++){
		cin >> s1 >> s2;
		if(s1.size() != s2.size()){
			printf("0\n");
			continue;
		}
		else{
			find(s1, s2);
		}
	}
	/*sort(d + 1, d + n + 1);
	sort(d + n + 1, d + n + sum + 1);
	for(int i = 1, j = 1; i <= n && j <= cnt;){
		
	}
	for(int i = 1; i <= q; i++){
		printf("%d\n", ans[i]);
	}*/
	return 0;
}
