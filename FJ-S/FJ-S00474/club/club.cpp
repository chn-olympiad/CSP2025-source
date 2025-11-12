#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w; 
}
const int MAXN = 1e5 + 8;
int n,nxtbest[MAXN],cha[MAXN];
struct node{
	int a,b,c;
}A[MAXN];
bool cmp(int x,int y){
	return cha[x] > cha[y];
}
void solve(){
	n = read();
	vector<int> vec[3];
	for(int i = 1;i <= n;i++){
		A[i].a = read();A[i].b = read();A[i].c = read();
		if(A[i].a >= A[i].b && A[i].a >= A[i].c){
			vec[0].push_back(i);
			if(A[i].b >= A[i].c) nxtbest[i] = 1,cha[i] = A[i].a - A[i].b;
			else nxtbest[i] = 2,cha[i] = A[i].a - A[i].c;
		}
		else if(A[i].b >= A[i].a && A[i].b >= A[i].c){
			vec[1].push_back(i);
			if(A[i].a >= A[i].c) nxtbest[i] = 0,cha[i] = A[i].b - A[i].a;
			else nxtbest[i] = 2,cha[i] = A[i].b - A[i].c;
		}
		else{
			vec[2].push_back(i);
			if(A[i].a >= A[i].b) nxtbest[i] = 0,cha[i] = A[i].c - A[i].a;
			else nxtbest[i] = 1,cha[i] = A[i].c - A[i].b;
		}
	}
	if(vec[0].size() > n / 2){
		sort(vec[0].begin(),vec[0].end(),cmp);
		for(int i = (int)vec[0].size() - 1;i >= n / 2;i--){
			vec[nxtbest[vec[0][i]]].push_back(vec[0][i]);
		}
		for(int i = (int)vec[0].size() - 1;i >= n / 2;i--) vec[0].pop_back();
	}
	else if(vec[1].size() > n / 2){
		sort(vec[1].begin(),vec[1].end(),cmp);
		for(int i = (int)vec[1].size() - 1;i >= n / 2;i--)
			vec[nxtbest[vec[1][i]]].push_back(vec[1][i]);
		for(int i = (int)vec[1].size() - 1;i >= n / 2;i--) vec[1].pop_back();
	}
	else{
		sort(vec[2].begin(),vec[2].end(),cmp);
		for(int i = (int)vec[2].size() - 1;i >= n / 2;i--)
			vec[nxtbest[vec[2][i]]].push_back(vec[2][i]);
		for(int i = (int)vec[2].size() - 1;i >= n / 2;i--) vec[2].pop_back();
	}
	int ans = 0;
	for(auto x : vec[0]) ans += A[x].a;
	for(auto x : vec[1]) ans += A[x].b;
	for(auto x : vec[2]) ans += A[x].c;
	cout << ans << "\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;T = read();
	while(T--)
		solve();
	return 0;
} 
