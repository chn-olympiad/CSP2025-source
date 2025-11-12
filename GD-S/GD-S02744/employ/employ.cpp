#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 105;
const int M = 998244353;
int n,m,a[N];
char s[N];
int c[N];
int p[15];

inline int qpow(int x,int y){
	int tmp = 1;
	while(y){
		if(y&1) tmp = (tmp*x)%M;
		x = (x*x)%M;
		y >>= 1;
	}
	return tmp;
}
inline bool check(){
	int res = 0,now = 0;
	for(int i=1;i<=n;i++){
		if(now>=c[p[i]]){
			now++;
			continue;
		}
		if(s[i]=='1') res++;
		else{
			now++;
		}
	}
	if(res>=m) return 1;
	return 0;
}

inline bool xinga();
int pre[N],f[N][N][N][N];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	//if(xinga()) return 0;
	
	if(n<=11){
		for(int i=1;i<=n;i++){
			p[i] = i;
		}
		int ans = 0;
		do{
			if(check()){
				ans++;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;	
	}
	else{
		sort(c+1,c+n+1);
		int now = 0;
		for(int i=0;i<=n;i++){
			while(now+1<=n && c[now+1]<=i){
				now++;
			}
			pre[i] = now;
		}
		f[0][0][0][0] = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				int lim1 = min(pre[i-j-1],i);
				int lim2 = pre[i-j]-pre[i-j-1];
				for(int k=0;k<=lim1;k++){
					int lim3 = min(i-k,lim2);
					for(int l=0;l<=0;l++){
						int num = f[i][j][k][l];
						f[i+1][j+1][k][l] = (f[i+1][j+1][k][l]+(n-pre[i-j]-(i-k-l))*num%M)%M;
						f[i+1][j][k+l+1][0] = (f[i+1][j][k+l+1][0]+(pre[i-j]-k-l)*num%M)%M;
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=m;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=0;k++){
					ans = (ans+f[n][i][j][k])%M;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}



inline bool xinga(){
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			return 0;
		}
	}
	int cnt = 0;
	sort(c+1,c+n+1);
	int now = 0;
	for(int i=0;i<=n;i++){
		while(now+1<=n && c[now+1]<=i){
			now++;
		}
		pre[i] = now;
	}
	return 1;
}
