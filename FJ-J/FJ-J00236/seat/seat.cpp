#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 1005
#define M 15
#define PII pair<ll, ll>
#define INF (ll)1e18

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
}
ll n, m, r, a[N], b[M][M], cnt;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n=rd(), m=rd();
	for(int i=1; i<=n*m; i++) a[i]=rd();
	r=a[1];
	sort(a+1, a+n*m+1, greater<ll>());
	for(int i=1; i<=m; i+=2){
		for(int j=1; j<=n; j++) b[j][i]=a[++cnt];
		if(i+1<=m) for(int j=n; j>=1; j--) b[j][i+1]=a[++cnt];
	}
//	for(int i=1; i<=n; i++, puts("")) for(int j=1; j<=m; j++) cout<<b[i][j]<<' ';
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(b[i][j]==r) return printf("%d %d\n", j, i)&0;

	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/

