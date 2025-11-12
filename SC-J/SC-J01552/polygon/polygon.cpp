#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans;
bool vis[5050],flag=1;
void dfs(int x,int shang){
	if(x==0){
		int cnt=0,ji=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				cnt+=a[i];
				ji=a[i];
			}
		}
		if(cnt>ji*2){
			ans++;
		}
		return;
	}
	for(int i=shang+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x-1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		if(n==3){
			cout<<1;
			return 0;
		}
		int Aa=1,Bb=3,Cc=3;
		for(int i=4;i<=n;i++){
			Aa=Aa*2+Bb;
			Bb+=Cc;
			Cc++;
		}
		cout<<Aa;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,0);
	}
	cout<<ans%998244353;
	return 0;
}