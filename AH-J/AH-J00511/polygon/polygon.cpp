#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
int a[5050],b[5050];int n;
int ans=0;
void dfs(int x,int data,int bs){
	//cout<<data<<' ';
	if(bs>=3&&data<0) {
		ans++;
		//cout<<ans<<'\n';
	}
	for(int i=x+1;i<=n;i++){
		
			dfs(i,data-a[i],bs+1);		
	}
	return;
}
signed main(){
	 freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	if(a[n]==1){
		cout<<'0';
		return 0;//24fen!
	}
	
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1];
	}
	for(int i=1;i<=n;i++){
		a[i]=b[i];
		
	}
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],1);
	}
	cout<<ans%Mod;
}
