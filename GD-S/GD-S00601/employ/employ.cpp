#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=505,mo=998244353;
int n,m,s[N],c[N],ans,vis[N],a[N],f;
ll pw[N];
bool check() {
	int f=0,cnt=0;
	for(int i=1;i<=n;i++) {
		if(f>=c[a[i]]||s[i]==0) f++;
		else cnt++;
	}
	return cnt>=m;
}
void dfs(int x) {
	if(x==n+1) {
		if(check()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]==0) {
			vis[i]=1,a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)
	    scanf("%d",&c[i]);
	if(n==m){
		pw[0]=1;
		for(int i=1;i<=n;i++) {
			pw[i]=pw[i-1]*i%mo;
			if(s[i]==0||s[i]==1) f=1;
		}	
		if(f) cout<<0;
		else cout<<pw[n];
	}
	else {
		dfs(1); 	
		cout<<ans;
	}
	return 0;
}

