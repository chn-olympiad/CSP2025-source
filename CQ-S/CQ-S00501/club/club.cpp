#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;bool b=1,c=1,vis[N];
int T,n,a1[N],a2[N],a3[N],ans;
void dfs(int aa1,int aa2,int aa3,int s,int dep){
	if(dep==n){ans=max(ans,s);if(s==5)cout<<'\n'<<aa1<<' '<<aa2<<' '<<aa3<<'\n';return;}
	if(aa1>n/2)return;
	if(aa2>n/2)return;
	if(aa3>n/2)return;
	dfs(aa1+1,aa2,aa3,s+a1[dep+1],dep+1);
	dfs(aa1,aa2+1,aa3,s+a2[dep+1],dep+1);
	dfs(aa1,aa2,aa3+1,s+a3[dep+1],dep+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]>0)b=0;
			if(a3[i]>0)c=0;
		}if(b==1&&c==1){
			sort(a1+1,a1+n+1);
			for(int i=n;i>n/2;i--)ans+=a1[i];
			cout<<ans<<'\n';
		}
		else{dfs(0,0,0,0,0);cout<<ans<<'\n';}
	}
	return 0;
}
