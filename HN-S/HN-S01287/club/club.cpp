#include<bits/stdc++.h>
using namespace std;
int T,n;
struct pi{
	int a,b,c,id;
}s[200005];
struct node{
	int x,id;
};
vector<node>E[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T --){
		cin >> n;
		long long maxn = 0;
		E[1].clear();
		E[2].clear();
		E[3].clear();
		int l1 = 0,l2 = 0,l3 = 0;
		for(int i = 1 ; i <= n ; i ++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			if(s[i].a >= s[i].b && s[i].a >= s[i].c){
				l1 ++;
				maxn += s[i].a;
				E[1].push_back({s[i].a , i}); 
			}else if(s[i].b >= s[i].a && s[i].b >= s[i].c){
				l2 ++;
				maxn += s[i].b;
				E[2].push_back({s[i].b , i});
			}else{
				l3 ++;
				maxn += s[i].c;
				E[3].push_back({s[i].c , i});
			}
			s[i].id = i;
		}
//		cout << l1 <<" " << l2 <<" " << l3 <<" " << maxn << "\n";
		if(l1 > n / 2){
			priority_queue<int>q;
			for(int i = 0 ; i < E[1].size() ; i ++){
				int id = E[1][i].id;
				int x = E[1][i].x;
				if(s[id].b - x > s[id].c - x){
					q.push(s[id].b - x);
				}else{
					q.push(s[id].c - x);
				}
//				cout << s[id].b - x << " " << s[id].c - x << "\n";
			}
			for(int i = 1 ; i <= l1 - n / 2 ; i ++){
				maxn += q.top();
				q.pop();
			}
		}else if(l2 > n / 2){
			priority_queue<int>q;
			for(int i = 0 ; i < E[2].size() ; i ++){
				int id = E[2][i].id;
				int x = E[2][i].x;
				if(s[id].a - x > s[id].c - x){
					q.push(s[id].a - x);
				}else{
					q.push(s[id].c - x);
				}
			}
			for(int i = 1 ; i <= l2 - n / 2 ; i ++){
				maxn += q.top();
				q.pop();
			}
		}else{
			priority_queue<int>q;
			for(int i = 0 ; i < E[3].size() ; i ++){
				int id = E[3][i].id;
				int x = E[3][i].x;
				if(s[id].a - x > s[id].b - x){
					q.push(s[id].a - x);
				}else{
					q.push(s[id].b - x);
				}
			}
			for(int i = 1 ; i <= l3 - n / 2 ; i ++){
				maxn += q.top();
				q.pop();
			}
		}
		cout << maxn << "\n";
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


147325
*/ 
