#include<bits/stdc++.h>
using namespace std;
int n,m,ans,mod=998244353,c[500005],a[500005];
bool bj[500005];
string s;
void dfs(int d,int ss,int fq){
	if(d==n+1){
//		cout<<d<<" "<<ss<<" "<<fq<<"\n";
//		for(int i=1;i<=d;i++) cout<<a[i]<<" ";
//		cout<<"\n";
		if(ss>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			bj[i]=1;
			a[d]=i;
			if(fq>=c[i]){
				dfs(d+1,ss,fq+1);
			}else if(s[d-1]=='1'){
				dfs(d+1,ss+1,fq);
			}else{
				dfs(d+1,ss,fq+1);
			}
			bj[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	ans%=mod;
	cout<<ans;
	return 0;
}

