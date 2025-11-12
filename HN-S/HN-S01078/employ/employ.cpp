#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=555,mod=998244353;
int n,m;
int c[N],flg=1,aans=1,s[N],ans1,ans2,ans;
string ss;
int vis[N];
int cmp(int a,int b){
	return a<b;
}
void dfs(int num,int tot,int cnt){//当前位置  录取数  淘汰数 
	num++;
	if(num<=n && tot==m){
		int k=n-num+1;
		int f=1;
		for(int i=1;i<=k;i++)
			(f*=i)%=mod;
		(ans2+=f)%=mod;
		return ;
	}
	if(num==n+1 && tot==m){
		(ans1+=1)%=mod;
	}
	if(m-tot>n-num+1){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(s[num]==1){
			if(cnt>=c[i]){
				vis[i]=1;
				dfs(num,tot,cnt+1);
				vis[i]=0;
			}else{
				vis[i]=1;
				dfs(num,tot+1,cnt);
				vis[i]=0;
			}
		}else if(s[num]==0){
			vis[i]=1;
			dfs(num,tot,cnt+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++){
		s[i]=ss[i-1]-'0';
		if(ss[i-1]!='1') flg=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1,cmp);
	if(flg){	
		for(int i=n;i>=1;i--)
			(aans*=(i%mod))%=mod;
		cout<<aans;
		return 0;
	}
	dfs(0,0,0);
	cout<<(ans1+ans2)%mod;
	return 0;
}

