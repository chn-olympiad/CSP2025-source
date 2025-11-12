#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10; 
int t,n,cnt;
int a[N],b[N],c[N],lp[5];
int d[N][5];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(int dep,int now){
	if(dep==n+1){
		cnt=max(cnt,now);
		return;
	} 
	for(int i=1;i<=3;i++){
		now+=d[dep][i];
		if(lp[i]>n/2) return;
		lp[i]++;
		dfs(dep+1,now);
		lp[i]--;
		now-=d[dep][i];
	}
}
void solve(){
	n=read();
	int k=n/2;
	for(int i=1;i<=n;i++) lp[i]=0;
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		d[i][1]=a[i],d[i][2]=b[i],d[i][3]=c[i];
	}
	if(n==2){
		write(max({a[1]+b[2],a[1]+c[2],b[1]+a[2],b[1]+c[2],c[1]+a[2],c[1]+b[2]}));
		putchar('\n');
		return;
	}
	bool f1=1;
	for(int i=1;i<=n;i++){
		if(b[i]!=0||c[i]!=0) f1=0;
	}
	if(f1){
		sort(a+1,a+1+n);
		int s=0,ans=0;
		for(int i=n;i>=1;i--){
			ans+=a[i];
			s++;
			if(s+1>k) break;
		}
		write(ans);
		putchar('\n');
		return;
	}
	bool f2=1;
	for(int i=1;i<=n;i++) if(c[i]!=0) f2=0;
	if(f2){
		sort(b+1,b+1+n);
		sort(a+1,a+1+n);
		return;
	}
	if(n<=10){
		cnt=0;
		dfs(1,-1);
		write(cnt);
		putchar('\n');
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
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

*/
