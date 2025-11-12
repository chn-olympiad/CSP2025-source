#include<bits/stdc++.h>
#define PR pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 1e5+5;
int n, a[MAXN][3];
bool vst[MAXN];

inline int Calc(int s){
	for(int i = 0; i < n; i++)	vst[i] = false;
	priority_queue<PR> pq;
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i][s];
		for(int j = 0; j < 3; j++){
			if(s == j)	continue;
			pq.push({a[i][j]-a[i][s], i+j*n});
		}
	}
	int cnt[3] = {0, 0, 0}; cnt[s] = n;
	while(!pq.empty()){
		PR tmp = pq.top(); pq.pop();
		if(cnt[s] <= n/2 and tmp.fi <= 0)	break;
		int x = tmp.se%n, y = tmp.se/n;
		if(vst[x] or cnt[y] >= n/2)	continue;
		vst[x] = true;
		sum += tmp.fi;
		--cnt[s], ++cnt[y];
	}
	for(int i = 0; i < 3; i++)	assert(cnt[i] <= n/2);
	return sum;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++)	scanf("%d", &a[i][j]);
		int ans = max(max(Calc(0), Calc(1)), Calc(2));
		printf("%d\n", ans);
	} 
	
	return 0;
}
/*
不存在某一个部门被分配 > n/2 个新成员。

感觉用这个东西 DP 是不是复杂了。
直接按照值大小排序，贪心取最大的。如果超了就不取了。
这玩意儿显然有问题。 

多半需要用摩尔投票吧？记得是怎么做的吗？
维护一个 pair，表示分类 & 个数。
那你摩尔投票也只能维护 O(n^2) DP。
有问题吧？摩尔投票是能找出那个绝对众数。并非能保证不存在。

考虑只有两个部门的时候怎么做。 
显然只能对半分。按照差值排名。

那么我们考虑先将 n 个全部放到部门一。然后调整。
注意调整的上下界即可。
不太敢保证是对的。不过写起来不麻烦。 

感觉还是会有点问题。
反悔贪心。我们可以做两个部门的情况。
需要拓展到三个部门。
感觉其实可以钦定一个一开始会超的。然后跑三次。 

过会儿再回来卡常。 



There are a lot of fish left in the sea
there are a lot of fish in buisness suits
they talk and walk on human feet
visit doctors, have weak knees

我草我没复习 AC 自动机 
*/