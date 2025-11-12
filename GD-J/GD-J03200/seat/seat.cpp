#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;
int read(){
    int x=0, f=1;
    char ch=getchar();
    for(ch;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
    for(ch;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
constexpr int INF=1e18, N=105;
int n, m, x=1, y=1; // 第 x 列, 第 y 行    共 n 行, m 列 
pii a[N*N]; // 第一维保存分数, 第二维保存编号 
inline bool cmp(pii x, pii y){
	return x.st>y.st;	
}
inline void nxt(){
	if(x&1){
		if(y==n)
			x++;
		else
			y++;
	}else{
		if(y==1)
			x++;
		else
			y--;
	}
}
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
	n=read(), m=read();
	for(int i=1;i<=n*m;i++) a[i].st=read(), a[i].nd=i;
	sort(a+1, a+1+n*m, cmp);
	for(int i=1;i<=n*m;i++){
		auto [sco, id]=a[i];
		if(id==1){
			cout<<x<<' '<<y;
			break;
		}
		nxt();
	}
	return 0;
}

