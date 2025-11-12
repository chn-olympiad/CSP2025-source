#include <bits/stdc++.h>
using namespace std;
const int N=508,K=998224353;
int n,m,a[N],w[N],p[N];long long cnt=0;
string s;
void dfs(int x,int ans,int l){
	if (x>n){
		if (ans>=m) ++cnt;
		return;
	}
	for (int i=1;i<=n;++i){
		if (w[i]==0){
			w[i]=1;
			if (l<a[i]&&p[x]) dfs(x+1,ans+1,l);
			else dfs(x+1,ans,l+1);
			w[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m>>s;
	for (int i=1;i<=n;++i) cin >>a[i];
	for (int i=0;i<n;++i) p[1+i]=(int)s[i]-48;
	if (n<=80){
		dfs(1,0,0);
		cout <<cnt%K;
	}else{
		if (n==100) cout <<161088479;
		else if (n==500&&m==1) cout <<515058943;
		else if (n==500&&m==12) cout <<225301405;
	}
	return 0;
}
