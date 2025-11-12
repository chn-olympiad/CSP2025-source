#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
string s;
int n,m,c[N],kk=0,res=0,f[N][N];
int cnt=0,aaa=0;
bool vis[N];
void dfs(int dep,int k){
	if(dep==n+1){
		if(k>=m){
			cnt=(cnt+1)%998244353;
			
		}
		return ;
	}
	if(k>=m){
		int cc=1;
		for(int i=1;i<=n-dep+1;i++){
			cc=cc*i%998244353;
		}
		cnt=(cnt+cc)%998244353;
		return ;
	}
	if(k+n-dep+1<m){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			aaa++;
			vis[i]=1;
			int h=0;
			if(s[dep]=='1'&&c[i]>dep-1-k?1:0)h=1;
			dfs(dep+1,k+h);
			vis[i]=0;
		}
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
//		k[i+1]=k[i]+s[i]-'0';
		res+=s[i]-'0';
		if(c[i]==0)kk++;
	}
	if(res<m){
		cout<<0;
		return 0;
	}
//	if(res==n){
		
		if(n-kk<m){
			cout<<0;
			return 0;
		}
//		cnt=1;
//		for(int i=1;i<=n;i++){
//			cnt=cnt*i%998244353;
//		}
//		cout<<cnt;
//		return 0;
//	}
//	if(m==1){
////wish to get good grades	
//	}
	dfs(1,0);
	cout<<cnt;
	return 0;
} 
