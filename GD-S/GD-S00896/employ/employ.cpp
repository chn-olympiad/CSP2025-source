#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=666;
int jc[N];
char tmp;
bool a[N],cho[N];
int n,m,c[N],ans,d[N];
void dfs(int k,int cnt){
//	cout<<k<<' '<<d[k]<<endl;
	if(cnt>=c[d[k]]||!a[k])cnt++;
	if(k==n){
//		if(cnt<=n-m)for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<cho[i]<<' ';cout<<endl;
		if(cnt<=n-m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!cho[i]){
//			cout<<cho[i]<<' '<<i<<endl;
			cho[i]=1;
			d[k+1]=i;
//			cout<<k+1<<' '<<d[k+1]<<' '<<i<<endl;
			dfs(k+1,cnt);
			cho[i]=0;
		}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		jc[i]=1ll*jc[i-1]*i%mod;
	for(int i=1;i<=n;i++)
		cin>>tmp,a[i]=tmp=='1';
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		cho[i]=1;
		d[1]=i;
		dfs(1,0);
		cho[i]=0;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
3 2
101 1 1 2
*/
