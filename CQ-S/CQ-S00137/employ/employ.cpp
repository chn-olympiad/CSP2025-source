#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define db double
#define pb push_back
#define vec vector
#define fi first
#define se second
#define lwz lower_bound
#define lowbit(x) (x&(-x))
#define popc(x) __builtin_popcount(x)
#define ull unsigned long long
#define il inline
using namespace std;
std:: mt19937 rng(time(0));
const int N=505;
const int mod=998244353;
int n,m,c[N],p[N],bj[N],ans;
bool s[N];
void dfs(int t){
	if(t==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!s[i]||sum>=c[p[i]])sum++;
		}
		if(n-sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!bj[i]){
			bj[i]=1;
			p[t]=i;
			dfs(t+1);
			bj[i]=0;
		}
	}
} 
il void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		if(c>'0')s[i]=1;
		else s[i]=0; 
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;return;
	} 
	cout<<0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int TTT=1;;
	while(TTT--)work();
	return 0;
} /*
我们应该把c相同的一起考虑，这样最后答案乘上每个颜色的阶乘数就行了
我去，我不会。。。。
这个数会被搞掉，当且仅当前面0的数量加上被搞掉的数的数量大于等于c_i 
对于m等于1，就求全都被搞掉的情况数，然后每个数可以选的下标是一个区间，和s为0的位置 
我怎么连这个都不会，真的毁了 
我甚至连有A性质加m=1都不会。。。
靠了计数白练习了。。。 
*/ 
