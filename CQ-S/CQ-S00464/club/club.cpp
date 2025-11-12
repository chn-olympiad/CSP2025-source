#include<bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=(j);i<=(k);++i)
#define rep1(i, j, k) for(int i=(k);i<=(j);--i) 
#define pii pair<int, int>
#define pb push_back
#define ft first
#define sd second

using namespace std;

int read(){
	int s=0, h=1;
	char x=getchar();
	while(!isdigit(x)){
		if(x=='-') h=-1;
		x=getchar();
	}
	while(isdigit(x)){
		s=(s<<3)+(s<<1)+x-'0';
		x=getchar();
	}
	return s*h;
}

void write(int x){
	if(x<0) putchar('-'), x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=1e5+5;
int n;
int a[N][3];

int cnt[3];
int v[3][N];

priority_queue<int> s;

void solve(){
	
	n=read();
	rep(i, 1, n) rep(j, 0, 2) a[i][j]=read();
	
	rep(i, 0, 2) cnt[i]=0;
	int ans=0;
	rep(i, 1, n){
		int p=0;
		if(a[i][1]>a[i][p]) p=1;
		if(a[i][2]>a[i][p]) p=2;
		
		v[p][++cnt[p]]=i;
		ans+=a[i][p];
		
	}
	
	int p=0;
	if(cnt[1]>cnt[p]) p=1;
	if(cnt[2]>cnt[p]) p=2;
	
	if(cnt[p]>(n>>1)){
		
		while(!s.empty()){
			s.pop();
		}
		rep(i, 1, cnt[p]){
			int j=v[p][i];
			int k=a[j][0];
			if(p==0) k=max(a[j][1], a[j][2]);
			if(p^1) k=max(k, a[j][1]);
			if(p^2) k=max(k, a[j][2]);
			
			s.push(k-a[j][p]);
		}
		
		while((int)s.size() > (n>>1)){
			ans+=s.top(); s.pop();
		}
		
	}
	
	write(ans);
	puts("");
	
	
}

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T=1;
	T=read();
	while(T--) solve();
	
	return 0;
}// 14.41
