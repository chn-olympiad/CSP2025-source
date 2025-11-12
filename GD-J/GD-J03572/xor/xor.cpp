#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],n,k,ans,vis[N];
ll o,z;
void solve(){
	bool flag=false;
	int cnt=0,sum=0;
	if(a[1]!=1) flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
		else sum++,flag=true;
	}
	if(!flag){
		if(!k) cout<<n/2;
		else cout<<n;	
		return;
	}
	if(k==1){
		cout<<cnt;
	}else if(k==0){
		int add=sum;
		for(int i=1;i<n;i++){
			if(vis[i]) continue;
			if(a[i]==1&&a[i+1]==1){
				add++;
				vis[i+1]=1;
			}
		}
		cout<<add;
	}else{
		cout<<2;
	}
	return;
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	solve();
	return 0;
}
