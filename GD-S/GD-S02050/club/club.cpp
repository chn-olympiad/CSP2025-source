#include<bits/stdc++.h>
#define int long long
#define getchar() getchar_unlocked()
const int N = 1e5 + 6;
void read(int& x){
	x = 0; int f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch == '-') f = -1;
	for(;isdigit(ch);ch=getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
	x *= f; 
}
void print(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x%10+48);
}
int T,n,maxn,cur[4],ans;
struct member{
	int val[4],fanhui,maxn,lessmaxn;
}ori[N]; 
void reset(int x){
	memset(ori, 0, sizeof 0);
	ans = cur[1] = cur[2] = cur[3] = 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T); 
	while(T--){
		std::priority_queue<int, std::vector<int>, std::greater<int>> fanhui[4];
		read(n); maxn = n / 2;
		for(int i=1;i<=n;i++){
			read(ori[i].val[1]); read(ori[i].val[2]); read(ori[i].val[3]);
			if(ori[i].val[1] >= ori[i].val[2] and ori[i].val[1] >= ori[i].val[3] and ori[i].val[2] >= ori[i].val[3]) ori[i].fanhui = ori[i].val[1] - ori[i].val[2], ori[i].maxn = 1, ori[i].lessmaxn = 2;
			else if(ori[i].val[1] >= ori[i].val[2] and ori[i].val[1] >= ori[i].val[3] and ori[i].val[3] >= ori[i].val[2]) ori[i].fanhui = ori[i].val[1] - ori[i].val[3], ori[i].maxn = 1, ori[i].lessmaxn = 3;
			else if(ori[i].val[2] >= ori[i].val[1] and ori[i].val[2] >= ori[i].val[3] and ori[i].val[1] >= ori[i].val[3]) ori[i].fanhui = ori[i].val[2] - ori[i].val[1], ori[i].maxn = 2, ori[i].lessmaxn = 1;
			else if(ori[i].val[2] >= ori[i].val[1] and ori[i].val[2] >= ori[i].val[3] and ori[i].val[3] >= ori[i].val[1]) ori[i].fanhui = ori[i].val[2] - ori[i].val[3], ori[i].maxn = 2, ori[i].lessmaxn = 3;
			else if(ori[i].val[3] >= ori[i].val[2] and ori[i].val[3] >= ori[i].val[1] and ori[i].val[1] >= ori[i].val[2]) ori[i].fanhui = ori[i].val[3] - ori[i].val[1], ori[i].maxn = 3, ori[i].lessmaxn = 1;
			else ori[i].fanhui = ori[i].val[3] - ori[i].val[2], ori[i].maxn = 3, ori[i].lessmaxn = 2;
		}
		std::sort(ori + 1, ori + 1 + n, [](member a, member b){return a.val[a.maxn] > b.val[b.maxn];});
		for(int i=1;i<=n;i++){
			if(cur[ori[i].maxn] >= maxn){
				if(ori[i].val[ori[i].maxn] - fanhui[ori[i].maxn].top() > ori[i].val[ori[i].lessmaxn]) ans += (ori[i].val[ori[i].maxn] - fanhui[ori[i].maxn].top()), fanhui[ori[i].maxn].pop(), fanhui[ori[i].maxn].push(ori[i].fanhui);
				else ans +=ori[i].val[ori[i].lessmaxn], cur[ori[i].lessmaxn]++;
			}
			else ans += ori[i].val[ori[i].maxn], cur[ori[i].maxn]++, fanhui[ori[i].maxn].push(ori[i].fanhui);
		}
		print(ans); putchar('\n'); 
		reset(n);
	}
	return 0;
}
