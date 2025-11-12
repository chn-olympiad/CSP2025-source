#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+5;
int n;

struct node{
	int p1,p2,p3;
}a[N];

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin >> T;
	while(T--){
		//初始化
		vector <pair<int,int>> c[4];
		pair<int,int> len[4];
		//输入
		cin >> n;
		int half_n = n/2;
		for (int i = 1;i <= n;i++){
			cin >> a[i].p1 >> a[i].p2 >> a[i].p3;
			//判断该同学应放进哪个社团（贪心）
			int maxx = max(a[i].p1,max(a[i].p2,a[i].p3));
			if (maxx == a[i].p1) c[1].push_back({i,a[i].p1});
			else if(maxx == a[i].p2) c[2].push_back({i,a[i].p2});
			else c[3].push_back({i,a[i].p3});
		}
		//计算不考虑人数情况下的最优答案
		ll ans=0;
		for (int i = 1;i <= 3;i++){
			for (auto j:c[i]) ans += j.second;
		}
//		cout << ans << ' ';
		//检查当前方案是否合法
		for (int i = 1;i <= 3;i++){
			len[i] = {i,c[i].size()};
		}
		sort(len+1,len+4,cmp);
//		for (int i = 1;i <= 3;i++) cout << len[i].first << ' ' << len[i].second << '\n';
		sort(c[1].begin(),c[1].end(),cmp);
		sort(c[2].begin(),c[2].end(),cmp);
		sort(c[3].begin(),c[3].end(),cmp);
//		for(auto i:c[1]) cout << i.first << ':' << i.second << ' ';
//		cout << '\n';
//		for(auto i:c[2]) cout << i.first << ':' << i.second << ' ';
//		cout << '\n';
//		for(auto i:c[3]) cout << i.first << ':' << i.second << ' ';
//		cout << '\n';

		//处理人数超额小组

		int num = len[3].first,len_num = len[3].second;//num记录人数最多的小组，len_num记录该小组人数
		if (len_num <= half_n){//合法
			cout << ans << '\n';
			continue;
		}
		//非法
		vector <int> down;//记录第i个人被处理后的损失
		for (int i = 0;i < len_num;i++){
			int tmp_num = c[num][i].first,tmp_val = c[num][i].second,maxx=0;
			if (num == 1){
				maxx = max(a[tmp_num].p2,a[tmp_num].p3);
			}
			else if (num == 2){
				maxx = max(a[tmp_num].p1,a[tmp_num].p3);
			}
			else maxx = max(a[tmp_num].p1,a[tmp_num].p2);
			down.push_back(tmp_val-maxx);
		}
		sort(down.begin(),down.end());
		for(int i = 0;i < len_num-half_n;i++) ans -= down[i];
		cout << ans << '\n';
	}
	return 0;
}
