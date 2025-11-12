#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
const long long MOD=998244353;
long long C[5010][5010];
long long ans=0;
void dfs(int now,long long num,int mx,int cns){
	//if(n-now<3-cns)return;
	if(now==n+1){
		if(cns>=3&&num>mx*2)ans++;
		ans%=MOD;
		return;
	}
	dfs(now+1,num,mx,cns);
	dfs(now+1,num+a[now],max(mx,a[now]),cns+1);
}
set<int>st;
void init(){
	for(int i=0;i<=5000;i++){
		C[i][i]=C[i][0]=1;
		C[i][1]=i;
		for(int j=i;j>=1;j--){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st.insert(a[i]);
	}
	if(st.size()==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=C[n][i];
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
//恶心死我了，差点忘记取模，蒟蒻只会打爆力 
