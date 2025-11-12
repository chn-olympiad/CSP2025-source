#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool b[5005]{0};
long long rty=0;
void dfs(int cnt,int ans,int maxn,int zz){
	if(cnt==ans+1){
		if(zz>maxn*2){
			rty+=1;
		}
		return;
	}
	for(int i=1;i<n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(cnt+1,ans,max(maxn,a[i]),zz+a[i]);
			b[i]=0;
		}
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,0,0);
		for(int j=0;j<5004;j++){
			b[i]=0;
		}
	}
	cout<<rty %998244353;
	fclose(stdin);
	fclose(stdout);
}
