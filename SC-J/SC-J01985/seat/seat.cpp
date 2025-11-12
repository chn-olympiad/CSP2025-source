#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
using AR=array<int,2>;
const int MAXN=105,MAXD=15;
int scores[MAXN],dt[MAXD][MAXD];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;cin>>n>>m;//n和m值域为1~10，不会爆int 
	REP(i,1,n*m)cin>>scores[i];//分数值域为1~100，不会爆int 
	int Rscore=scores[1];//排序后顺序会被打乱，因此先把小R的分数记下来 
	auto cmp=[](int a,int b){return a>b;};//题目要求从高到低分配 
	sort(scores+1,scores+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		//奇数列从前到后放置，偶数列从后到前放置 
		if(j%2)for(int i=1;i<=n;i++)dt[i][j]=scores[++cnt];
		else for(int i=n;i>=1;i--)dt[i][j]=scores[++cnt];
	}
	//题目保证成绩互不相同，只要某个位置分数和小R一样就是小R的位置 
	REP(i,1,n)REP(j,1,m)if(dt[i][j]==Rscore)return cout<<j<<" "<<i,0;//要求先输出列后输出行 
	return 0;
}
//模拟 
//11-01 08:51:47