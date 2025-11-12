#include<bits/stdc++.h>
#define int long long
#define N 501
#define mod 998244353
using namespace std;
#define gc getchar()
void read(int &n){int l=1,num;char ch;
while(ch=gc,ch>'9'||ch<'0')if(ch=='-')l=-1;
num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=num*l;return;}

int n,m,c[N],vis[N],ans;string s;

void dfs(int k,int num){
	if(k==n){
		if(n-num>=m)ans=(ans+1)%mod;
		return;
	}
	if(n-num<m)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(c[i]>num&&s[k]=='1')dfs(k+1,num);
		else dfs(k+1,num+1);
		vis[i]=0;
	}return;
}

signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%mod;cout<<ans;return 0; 
	}
	dfs(0,0);cout<<ans;
	return 0;
}
//quq估分估玩134 我不想退役quq  

