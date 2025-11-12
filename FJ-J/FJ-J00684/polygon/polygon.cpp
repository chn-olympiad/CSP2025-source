#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000],ans,cnt;
bool vis[10000];
void search(int p,int k){
	if(p>k){
		cnt++;
		cnt%=998244353;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				search(p+1,k);
			}
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
	if(n==3){
		cout<<1;
		return 0;
	}
	for(int i=3;i<=n;i++){
		search(1,i);
		ans+=cnt;
		ans%=998244353;
		memset(vis,0,sizeof(vis));
	}
	cout<<ans;
	return 0;
}
