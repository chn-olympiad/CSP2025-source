#include<bits/stdc++.h>
#define debug 0
#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
//debug 1 -> start debug
using namespace std;
const int N =1e4 + 100;
int n,m,k,fa[N];
int find(int x){
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
bool merge(int x,int y){
	x = find(x); y = find(y);
	if(x == y)return 1;
	fa[x] = y;
	return 0;
}
int read(){
	int f = 0,k = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')k = -1;
		ch = getchar();
	}
	while(isdigit(ch))f = f * 10 + ch - '0',ch = getchar();
	return f;
}
void the_main(){
	//cin >> n >> m >> k;
	n = read(),m = read(),k = read();
	priority_queue<pip,vector<pip>,greater<pip> > pq;
	for(int i = 1;i<= N - 10;i++)fa[i] = i;
	for(int i = 1,_1,_2,_3;i<= m;i++){
		//cin >> _1 >> _2 >> _3;
		_1 = read(),_2 = read(), _3 = read();
		pq.push({_3,{_2,_1}});
	}
	for(int i = 1;i<= k;i++){
		int q;
		//cin >> q;
		q = read();
		for(int j = 1,_;j<= n;j++){
			//cin >> _;
			_ = read();
			pq.push({_,{j,i + (int)1e4}});
		}
	}
	int ans = 0;
	while(!pq.empty()){
		int l = pq.top().second.first,r = pq.top().second.second,w = pq.top().first;
		pq.pop();
		if(merge(l,r))continue;
		ans += w;
	}
	cout << ans;
}

signed main(){
	#if debug == 1
	cout << "start debug";
	#else
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	the_main();
	#if debug != 1
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
