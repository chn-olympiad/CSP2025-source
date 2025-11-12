#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		int ans=0;
		bool vis[200005]={0};
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1&&vis[i]==0&&vis[i+1]==0){
				ans++;
				vis[i]=1,vis[i+1]=1;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1)cnt++;
		cout<<cnt;
		return 0;
	}
	return 0;
}
