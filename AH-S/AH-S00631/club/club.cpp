#include<bits/stdc++.h>
#define int long long
#define MAXN 3 * 100010
using namespace std;
int N,A[4][MAXN],num;
void dfs(int n,int ans,int cnta,int cntb,int cntc){
	if(n == N + 1){
		num = max(num,ans);
		return;
	}
	if(cnta < N/2)dfs(n + 1,ans + A[1][n],cnta + 1,cntb,cntc);
	if(cntb < N/2)dfs(n + 1,ans + A[2][n],cnta,cntb + 1,cntc);
	if(cntc < N/2)dfs(n + 1,ans + A[3][n],cnta,cntb,cntc + 1);
}

struct node{
	int a,idx;
	bool operator < (const node & rhs)const{return a < rhs.a;}
};
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int T;cin>>T;while(T--){
	num = 0;
	cin>>N;
	bool a = true;
	for(int i = 1;i <= N; i++){
		cin>>A[1][i]>>A[2][i]>>A[3][i];
		if(A[3][i] || A[2][i]) a = false;
	}
	if(a){
		sort(A[1] + 1, A[1] + 1 + N,greater<int>());
		for(int i = 1;i <= N / 2; i ++)num+=A[1][i];
		cout<<num<<endl;
		return 0;
	}else{
		dfs(1,0,0,0,0);
		cout<<num<<endl;
	}
}}
//Ren5Jie4Di4Ling5%
/*
3
30
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
30
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
*/
