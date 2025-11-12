#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[66],ans=0,vis[55],b[55];
string s;
const int M=998244353;
void dfs(int p){
	if(p==n+1){
		int sm=0,l=0;
		for(int i=1;i<=n;i++){
			if(l<b[i]){
				if(s[i-1]=='1')sm++;
				else l++;
			}
			else l++;
		}
		if(sm>=m){
			ans++;
	//		for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//			cout<<"\n";
		}
		ans%=M;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[p]=a[i];
			dfs(p+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	printf("%d",ans);
	return 0;
}
