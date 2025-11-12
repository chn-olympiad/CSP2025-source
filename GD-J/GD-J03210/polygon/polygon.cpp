#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5100,P=998244353;
template<typename T>inline void qr(T &x){
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		f=-1;
	for(;isdigit(c);c=getchar())
		x=x*10+c-48;
	x*=f;
}
template<typename T>inline void qw(T x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
		qw(x/10);
	putchar(x%10+48);
}
int n;
ll a[N],ans=0;
inline void dfs(int k,int m,ll mx,ll sum){
	if(k>n){
		if(m>=3&&sum>mx*2){
			ans++;
			if(ans==P)ans=0;
		}
		return;
	}
	if(n-k+m<=1)return;
	dfs(k+1,m,mx,sum);
	dfs(k+1,m+1,max(mx,a[k]),sum+a[k]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	qr(n);
	for(int i=1;i<=n;i++)
		qr(a[i]);
	dfs(1,0,0,0);
	qw(ans);
	putchar('\n');
	return 0;
}
