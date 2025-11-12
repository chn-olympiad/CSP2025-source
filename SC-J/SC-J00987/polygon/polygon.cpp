#include<bits/stdc++.h>
using namespace std;
template<typename P>
inline void read(P &x){
	P res = 0, f = 1;
	char ch = getchar();
	while(ch <'0' || '9' <ch){
		if(ch=='-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		res = (res*10) + (ch -'0');
		ch = getchar();
	}
	x = res * f;
}
template <typename Ty, typename ...Args>
inline void read(Ty &x, Args &...args){read(x);read(args...);}
const int N = 505;
int dp[N][N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans=0;
	read(n);
	vector<int>a(n+1);
	for(int i=1; i<=n; ++i)read(a[i]);
	for(int S=1; S <= (1<<n+1)-1; ++S){
		int Max=-1, sum=0;
		for(int i=1; i<=n; ++i){
			if(S & (1<<i)){
				Max=max(Max, a[i]);
				sum+=a[i];
			}
		}
		if(sum > 2 * Max){
			ans++;
		}
	}
	cout << ans/2;
	return 0;
}