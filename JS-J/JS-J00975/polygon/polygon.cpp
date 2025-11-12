#include <bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,ans,s[N],a[N],vis[N];
bool cm(int m){
	int sum=0,maxn=0;
	for(int i=1;i<=m;i++){sum+=a[i];maxn=max(maxn,a[i]);}
	if(m>=3&&sum*2>maxn)return 1;
	return 0;
}
void DFS(int dep,int last){
	if(dep>n)return;
	if(cm(dep)){ans++;return;}
	for(int i=last+1;i<=n;i++){
		if(vis[i]==true)continue;
		if(vis[i]==false){
			vis[i]=true;
			a[dep]=s[i];
			DFS(dep++,i);
			a[dep]=0;
			dep--;
		}
	}
}
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	DFS(1,1);
	cout<<ans%mod<<endl;
	return 0;
}
