#include<bits/stdc++.h>
using namespace std;
long long m,n,ans,pl,zr,pp,cnt;
string s;
long long c[1005],a[1005],vis[1005],d[1005],h[1005];
bool cheak(){
	pl=0;
	zr=0;
	for(int i=1;i<=n;i++){
		if(pl>=c[d[i]]){
			pl++;
			continue;
		}
		if(a[i]==0){
			pl++;
			continue;
		}
		zr++;
	}
	if(zr<m){
		return 0;
	}
	if(zr>=m){
		return 1;
	}
}
void dfs(int pos){
	if(pos==n+1){
		if(cheak()){
			ans++;
			ans=ans%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			d[pos]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=s.size();i++){
		a[i]=s[i-1]-'0';
		if(a[i]==1){
			cnt++;
		}
	}
	if(m==n){
		if(cnt==n){
			ans=1;
		    for(int i=1;i<=n;i++){
			ans=ans*i;
			ans=ans%998244353;
		    }
		    cout<<ans;
		    return 0;
		}
		if(cnt!=n){
			cout<<0;
			return 0;
		}
	}
	if(cnt>m){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
