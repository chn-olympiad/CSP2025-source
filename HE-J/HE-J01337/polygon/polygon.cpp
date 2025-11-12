#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans;
int v[5005];
int q[5005]; 
bool bd[5005],bz[5005],bn[25000005],bm[5005];
void dfs(int d,int z,int num,int m){
	if(bd[d]==1&&bz[z]==1&&bn[num]==1&&bm[m]==1) return;
	if(d==z){
		if(num>2*m){
			bd[d]=1;bz[z]=1;bn[num]=1;bm[m]=1;
			ans++;
			ans%=998244353;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(v[i]!=0) continue;
		v[i]=1;
		dfs(d+1,z,num+a[i],max(m,a[i]));
		v[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		memset(v,0,sizeof(v));
		dfs(0,i,0,-1);
	}
	cout<<ans%998244353;
	
	return 0;
}

