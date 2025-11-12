#include <bits/stdc++.h>
using namespace std;
int a[505],f[505],ti[505],c[505],n,m,ans=0;
void dfs(int step){
	if(step==n+1){
		int go=0;
		for(int i=1;i<=n;i++){
			if(go>=c[a[i]]||ti[i]==0) go++;
		}
		if(n-go>=m) ans=(ans+1)%998244353;
	}else{
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				a[step]=i;
				dfs(step+1);
				a[step]=0;
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=10){
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			ti[i]=c-'0';
		}
		for(int i=1;i<=n;i++) cin>>c[i];
		dfs(1);
		cout<<ans;
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
