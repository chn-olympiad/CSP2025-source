#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int s=0,f=1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s*10+ch-'0';
		ch = getchar();
	}
	return s*f;
}
int n,a[5005],vis[5005];
ll ans,N = 998244353;
void dfs(int x,int s,int m,int h,int l){
	if(x>n){
		return ;
	}
	if(s>=3){
		if(m>2*h && vis[l] == 0){
			ans++;
			ans %= N;
			//cout << h << " " << m << endl;
			vis[l] = 1;
		}
	}
	dfs(x+1,s+1,m+a[x+1],max(a[x+1],h),l+1);
	dfs(x+1,s,m,h,l);
	vis[l] = 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = read();
	bool one = 1;
	for(int i=1;i<=n;i++){
		a[i] = read();
		if(a[i] != 1){
			one = 0;
		}
	}
	if(one){
		for(int i=3;i<=n;i++){
			ll cnt=1;
			for(int j=n;j>i;j--){
				cnt*= j;
			}
			for(int j=n;j>i;j--){
				cnt/=(j-i);
			}
			ans+=cnt;
		}
		cout << ans;
	}else{
		dfs(0,0,0,0,0);
		cout << ans%N;
	}
	return 0;
}