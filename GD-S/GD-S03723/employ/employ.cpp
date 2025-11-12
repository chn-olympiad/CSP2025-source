#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int a[605];
int p[605];
bool vis[605];
long long dfs(int pos,int len,int s,int k){
	if(pos==n+1){
		return len>=m;
	}
	if(a[pos]==0) return dfs(pos+1,len,s+1,-1);
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(s>=p[i]){
			(sum+=dfs(pos+1,len,s+1,i))%=mod;
		}else{
			(sum+=dfs(pos+1,len+1,s,i))%=mod;
		}
		vis[i]=false;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='0'){
			a[i]=0;
		}else{
			a[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	cout<<dfs(1,0,0,-1); 
	return 0;
}
