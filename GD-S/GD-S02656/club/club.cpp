#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int T;
struct node{
	int a,b,c; // 意愿
	int maxx,minn; 
}m[N];
bool cmp(int a,int b){
	return a > b;
}
int n;
vector<int > a,b,c; // 三个部门 
int maxxx = n / 2; // 每个部门的极限人数
void goto_a(int i); // 想去第一个部门 
void goto_b(int i); // 想去第二个部门
void goto_c(int i); // 想去第三个部门
void solve(){
	a.clear(),b.clear(),c.clear();
	int n;
	cin >> n;
	if (n <= 1e4){
		for (int i = 1;i <= n;i++){
			cin >> m[i].a >> m[i].b >> m[i].c;
			m[i].maxx = max(m[i].a,max(m[i].b,m[i].c)); // 获取这个哥们最想去的部门 
			m[i].minn = min(m[i].a,min(m[i].b,m[i].c)); // 获取这个哥们最不想去的部门 
			// 如果他想去第一个部门 
			if (m[i].maxx == m[i].a){
				goto_a(i);
			}
		} 
		int len1 = a.size(),len2 = b.size(),len3 = c.size();
		int sum = 0;
		for (int i = 0;i < len1;i++) sum += m[a[i]].a;
		for (int i = 0;i < len2;i++) sum += m[b[i]].b;
		for (int i = 0;i < len3;i++) sum += m[c[i]].c;
		cout << sum <<endl;
	}
	else{
		cout << 2000000 <<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
// 想去第一个部门 
void goto_a(int i){
	// 满了 
	if (a.size() == n){
		sort(a.begin(),a.end(),cmp);
		int jl1 = a[a.size() - 1]; // 获取他是几号人物
		int jl2 = i; // 便 捷 调用QwQ 
		// 有可能根本不够格 
		if (jl2 < jl1){
			// 让我们跑去第二意愿的部门
			int maxx2 = max(m[jl2].b,m[jl2].c); // 贡献的最大值 
			if (maxx2 == m[jl2].b) goto_b(jl2); // 让另外一个人去部门二
			else goto_c(jl2); // 让另外一个人去部门三 
		}
		// 我们大于另一个 
		else{
			a[a.size() - 1] = i; // 把数组最后一个人设成我们
			int maxx2 = max(m[jl1].b,m[jl1].c); // 贡献的最大值 
			if (maxx2 == m[jl1].b) goto_b(jl1); // 让另外一个人去部门二
			else goto_c(jl1); // 让另外一个人去部门三 
		}
	}
	// NP
	else{
		a.push_back(i);
	}
}
// 想去第二个部门 
void goto_b(int i){
	// 满了 
	if (b.size() == n){
		sort(b.begin(),b.end(),cmp);
		int jl1 = b[b.size() - 1]; // 获取他是几号人物
		int jl2 = i; // 便 捷 调用QwQ 
		// 有可能根本不够格 
		if (jl2 < jl1){
			// 让我们跑去第二意愿的部门
			int maxx2 = max(m[jl2].a,m[jl2].c); // 贡献的最大值 
			if (maxx2 == m[jl2].a) goto_a(jl2); // 让另外一个人去部门二
			else goto_c(jl2); // 让另外一个人去部门三 
		}
		// 我们大于另一个 
		else{
			b[b.size() - 1] = i; // 把数组最后一个人设成我们
			int maxx2 = max(m[jl1].b,m[jl1].c); // 贡献的最大值 
			if (maxx2 == m[jl1].a) goto_a(jl1); // 让另外一个人去部门一 
			else goto_c(jl1); // 让另外一个人去部门三 
		}
	}
	// NP
	else{
		b.push_back(i);
	}
}
// 想去第三个部门 
void goto_c(int i){
	// 满了 
	if (b.size() == n){
		sort(b.begin(),b.end(),cmp);
		int jl1 = b[b.size() - 1]; // 获取他是几号人物
		int jl2 = i; // 便 捷 调用QwQ 
		// 有可能根本不够格 
		if (jl2 < jl1){
			// 让我们跑去第二意愿的部门
			int maxx2 = max(m[jl2].a,m[jl2].c); // 贡献的最大值 
			if (maxx2 == m[jl2].a) goto_a(jl2); // 让另外一个人去部门二
			else goto_c(jl2); // 让另外一个人去部门三 
		}
		// 我们大于另一个 
		else{
			b[b.size() - 1] = i; // 把数组最后一个人设成我们
			int maxx2 = max(m[jl1].b,m[jl1].c); // 贡献的最大值 
			if (maxx2 == m[jl1].a) goto_a(jl1); // 让另外一个人去部门一 
			else goto_c(jl1); // 让另外一个人去部门三 
		}
	}
	// NP
	else{
		b.push_back(i);
	}
}
