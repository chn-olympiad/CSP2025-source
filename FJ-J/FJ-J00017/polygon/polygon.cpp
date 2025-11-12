#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5005],c[5005][5005],ans;
bool f1=true;

void dfs(int id,int sum,int mx){
	if(id==n+1){
		if(sum>2*mx) ans=(ans+1)%M;
		return;
	}
	dfs(id+1,sum,mx);
	dfs(id+1,sum+a[id],max(mx,a[id]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=false;
	}
	if(f1){
		for(int i=1;i<=n;i++) c[i][1]=i;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=i;j++){
				c[i][j]=(c[i][j-1]*(i-j+1)/j)%M;
			}
		}
		for(int i=3;i<=n;i++) ans=(ans+c[n][i])%M;
	}else dfs(1,0,0);
	cout<<ans;
	return 0; 
}
