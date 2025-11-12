#include<bits/stdc++.h>
using namespace std;
int n,m,len;
const int mod=998244353;
int ans;
int a[100010];
string s;
int na[100010];
int vis[10010];
int p[10010];
void dfs(int t){
	if(t>n){
		int k=0;
		for(int i=1;i<=n;i++){
			if(a[p[i]]>na[i]){
				k++;
			}
			
		}
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<"\n";
//		cout<<"kk";
		if(k>=m)ans=(ans+1)%mod;
//		cout<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[t]=i;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	len=s.length();
	s=" "+s;
	int k=0;
	for(int i=1;i<=len;i++){
//		cout<<s[i]<<" ";
		na[i]=k;
		if(s[i]=='0'){
			k++;
			na[i]=1e9;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<na[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
