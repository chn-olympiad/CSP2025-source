#include<bits/stdc++.h>
using namespace std;
int n,sticks[5005],ans,a[5005];
bool f[5005]; 
bool ok(int p){
	int ps=0;
	for(int i=1;i<=p-1;i++){
		ps+=a[sticks[i]];
		if(ps>a[sticks[p]]) return true;
	}
	return false;
}
void dfs(int k,int tot){
	for(int i=1;i<=n;i++){
		if(!f[i]&&i>sticks[k-1]){
			sticks[k]=i;
			f[i]=1;
			if(k==tot){
				if(ok(tot)) ans++;
				//for(int i=1;i<=tot;i++) cout<<sticks[i]<<' ';
				//cout<<endl;
			}
			else dfs(k+1,tot);
			sticks[k]=0;
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,i);
		for(int j=1;j<=n;j++) f[j]=0;
	}
	cout<<ans%998244353;
	return 0;
}
