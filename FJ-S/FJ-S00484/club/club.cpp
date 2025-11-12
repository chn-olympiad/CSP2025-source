#include <bits/stdc++.h> 
typedef long long ll;     
using namespace std; 

const int N = 1e5 + 5; 

int T, n, a[N][5], id[N]; 

bool vis[N];     

ll ans, ans1, ans2, ans3; 

bool cmpA(int x, int y) {
	return a[x][1] > a[y][1];   
}   

bool cmpB(int x, int y) {
	return a[x][1] - a[x][2] > a[y][1] - a[y][2]; 
}

void GetA() {
	sort(id + 1, id + n + 1, cmpA); 
	for(int i = 1; i <= n / 2; i++) {
		ans += 1ll * a[id[i]][1]; 
	} 
	printf("%lld\n", ans); 
	return; 
}   

void GetB() {
	sort(id + 1, id + n + 1, cmpB);     
	for(int i = 1; i <= n / 2; i++) {
		ans += 1ll * a[id[i]][1]; 
	} 
	for(int i = n / 2 + 1; i <= n; i++) {
		ans += 1ll * a[id[i]][2]; 
	} 
	printf("%lld\n", ans); 
	return; 
}    

void dfs(int nw, ll ans1, ll ans2, ll ans3, int cnt1, int cnt2, int cnt3) {
	if(nw == n + 1) {
		ans = max(ans, ans1 + ans2 + ans3); 
		return;     
	} 
	if(cnt1 < n / 2) dfs(nw + 1, ans1 + a[nw][1], ans2, ans3, cnt1 + 1, cnt2, cnt3); 
	if(cnt2 < n / 2) dfs(nw + 1, ans1, ans2 + a[nw][2], ans3, cnt1, cnt2 + 1, cnt3); 
	if(cnt3 < n / 2) dfs(nw + 1, ans1, ans2, ans3 + a[nw][3], cnt1, cnt2, cnt3 + 1);       
	return; 
} 

bool cmp1(int x, int y) {
	return a[x][1] - max(a[x][2], a[x][3]) > a[y][1] - max(a[y][2], a[y][3]);  
} 

bool cmp2(int x, int y) {
	return a[x][2] - a[x][3] > a[y][2] - a[y][3];   
} 

bool cmp3(int x, int y) {
	return a[x][2] - max(a[x][1], a[x][3]) > a[y][2] - max(a[y][1], a[y][3]); 
}

bool cmp4(int x, int y) {
	return a[x][1] - a[x][3] > a[y][1] - a[y][3];   
} 

bool cmp5(int x, int y) {
	return a[x][3] - max(a[x][1], a[x][2]) > a[y][3] - max(a[y][1], a[y][2]); 
}

bool cmp6(int x, int y) {
	return a[x][1] - a[x][2] > a[y][1] - a[y][2];   
} 

void Main() {
	scanf("%d", &n); 
	ans = 0, ans1 = 0, ans2 = 0, ans3 = 0; 
	bool flagA = 1, flagB = 1; 
	for(int i = 1; i <= n; i++) {
		id[i] = i, vis[i] = 0; 
		for(int j = 1; j <= 3; j++) {
			scanf("%d", &a[i][j]);  
		}     
		if(a[i][2] != 0) flagA = 0;
		if(a[i][3] != 0) flagB = 0;    
	}  
	if(flagA == 1) { GetA(); return; }
	if(flagB == 1) { GetB(); return; }  
	if(n <= 10) { dfs(1, 0ll, 0ll, 0ll, 0, 0, 0); printf("%lld\n", ans); return; } 
	//
	sort(id + 1, id + n + 1, cmp1); 
	int ct = 0;  
	for(int i = 1; i <= n / 2; i++) { 
		if(a[id[i]][1] >= max(a[id[i]][2], a[id[i]][3])) {
			ans1 += 1ll * a[id[i]][1]; 
			vis[id[i]] = true; 
			ct++;        
		} 
		else break; 
	} 
	sort(id + 1, id + n + 1, cmp2); 
	int cnt2 = n - ct, cnt3 = 0; 
	for(int i = 1; i <= n; i++) {
		if(vis[id[i]]) continue; 
		if((a[id[i]][2] >= a[id[i]][3] && cnt3 < n / 2) || cnt2 > n / 2) ans1 += 1ll * a[id[i]][2], cnt2--, cnt3++; 
		else ans1 += 1ll * a[id[i]][3]; 
	} 
	//
	sort(id + 1, id + n + 1, cmp3); 
	for(int i = 1; i <= n; i++) vis[i] = 0;          
	ct = 0;  
	for(int i = 1; i <= n / 2; i++) { 
		if(a[id[i]][2] >= max(a[id[i]][1], a[id[i]][3])) {
			ans2 += 1ll * a[id[i]][2]; 
			vis[id[i]] = true; 
			ct++;        
		} 
		else break; 
	} 
	sort(id + 1, id + n + 1, cmp4); 
	cnt2 = n - ct, cnt3 = 0; 
	for(int i = 1; i <= n; i++) {
		if(vis[id[i]]) continue; 
		if((a[id[i]][1] >= a[id[i]][3] && cnt3 < n / 2) || cnt2 > n / 2) ans2 += 1ll * a[id[i]][1], cnt2--, cnt3++; 
		else ans2 += 1ll * a[id[i]][3];    
	} 
	//
	sort(id + 1, id + n + 1, cmp5); 
	for(int i = 1; i <= n; i++) vis[i] = 0;          
	ct = 0;  
	for(int i = 1; i <= n / 2; i++) { 
		if(a[id[i]][3] >= max(a[id[i]][1], a[id[i]][2])) {
			ans3 += 1ll * a[id[i]][3]; 
			vis[id[i]] = true; 
			ct++;        
		} 
		else break; 
	} 
	sort(id + 1, id + n + 1, cmp6); 
	cnt2 = n - ct, cnt3 = 0; 
	for(int i = 1; i <= n; i++) {
		if(vis[id[i]]) continue; 
		if((a[id[i]][1] >= a[id[i]][2] && cnt3 < n / 2) || cnt2 > n / 2) ans3 += 1ll * a[id[i]][1], cnt2--, cnt3++; 
		else ans3 += 1ll * a[id[i]][2];    
	} 
	//
	ans = max(ans1, max(ans2, ans3)); 
	printf("%lld\n", ans); 
	return; 
}

int main() { 
	freopen("club.in", "r", stdin);
//	freopen("in.txt", "r", stdin);  
	freopen("club.out", "w", stdout);   
	scanf("%d", &T); while(T--) {
		Main(); 
	}    
	return 0;     
}    
