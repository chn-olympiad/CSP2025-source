#include <bits/stdc++.h>
using namespace std;
using LL=long long;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

cst LL mod=998244353; 
int n;
vector<int> a, s;
vector<LL> pow2(60);
int sum=0;
inline LL DFS(cst int &le, cst int &ri, cst int &v, cst int &step){
	if (step==ri+1)return sum>v;
	sum+=a[step];
//	printf("chose: %d\n", step);
	LL res=DFS(le, ri, v, step+1);
	sum-=a[step];
//	printf("unchose: %d\n", step);
	res+=DFS(le, ri, v, step+1);
	return res%mod;
}
void solve_40pts(){
	sort(a.begin()+1, a.end());
	FOR (i, 1, n)s[i]=s[i-1]+a[i];
	LL ans=0;
	FOR (i, 3, n){//设定a[i]现在是最大的, 那么先求得在区间[1, i)中<=a[i]的个数 
		int j=upper_bound(s.begin(), s.end(), a[i])-s.begin();//找到第一个>a[i]的位置 
		if (i==j)continue;//没搞, 全都是<=的
		for (;j<i;j++)(ans+=DFS(1, j-1, a[i]-a[j], 1))%=mod;
//		printf("i=%d, j=%d\n", i, j);
	}
	printf("%lld", ans);
}
void solve_special(){
	LL cnt=0;
	FOR (i, 1, n)if (a[i]==1)cnt++;
	printf("%lld", LL(n)*(n-1)%mod*(n-2)%mod);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin>>n, a.resize(n+1), s.resize(n+1);
	FOR (i, 1, n)cin>>a[i];	
	if (n<=20)solve_40pts();
	else solve_special();
	return 0;
}
//Luogu SEAN2022NAES welcome to huguan!!!
//I guess that about T2, somebody will not check if the m equals to 1.
//I'm surfing on the Microsoft Edge now.
//Maybe I'll AFK soon. Hope I can get 324pts!!!
//I loved DJY. ~~But I hate her now, because she goosped me. The people like this is my hatest.~~ 