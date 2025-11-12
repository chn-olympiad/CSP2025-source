#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define LL long long
typedef pair<int, int> PII;
LL read(){LL x; scanf("%lld", &x); return x; }

const int N = 1e5 + 10;

int n;
int va[3];

int ans;
vector<int> gt[3]; 

void init(){
	ans = 0;
	for(int o = 0; o < 3; o ++)gt[o].clear();
}

void solve(int qid){
	init();
	
	n = read();
	for(int i = 1; i <= n; i ++){
		for(int o = 0; o < 3; o ++)va[o] = read();
		if(va[0] >= va[1] && va[0] >= va[2])ans += va[0], gt[0].push_back(va[0] - max(va[1], va[2]));
		else if(va[1] >= va[0] && va[1] >= va[2])ans += va[1], gt[1].push_back(va[1] - max(va[0], va[2]));
		else ans += va[2], gt[2].push_back(va[2] - max(va[0], va[1]));
	}
    
    for(int o = 0; o < 3; o ++)
    	if(gt[o].size() > n / 2){
    		sort(gt[o].begin(), gt[o].end());
    		for(int i = 0; i < gt[o].size() - n / 2; i ++)ans -= gt[o][i];
		}
    
    printf("%d\n", ans);
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    int tii = read();
    for(int z = 1; z <= tii; z ++)solve(z);
    return 0;
}

