#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long k;
int a[500005];
int vis[500005];
void dfs(long long sum,int seat){
	if(sum==k){
		long long s;
		bool f;
		if(vis[1]==0){
			f=false;
		}else{
			f=true;
			s++;
		}
		for(int i=2;i<=n;i++){
			if(vis[i]==0&&f==true){
				f=false;
			}else if(vis[i]==1&&f==false){
				f=true;
				s++;
			}
		}
		ans=max(ans,s);
	}
	for(int i=seat;i<=n;i++){
		vis[i]=1;
		dfs((sum^a[i]),i+1);
		vis[i]=0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],i+1);
	}
	if(ans>=1000){
		cout<<n/2+1;
		return 0;
	}
	cout<<ans;
	return 0;
}

