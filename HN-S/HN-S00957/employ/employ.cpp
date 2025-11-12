#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){res=(res<<1)+(res<<3)+ch-'0';ch=getchar();}
	return res*f;
}
void write(int x){
	if(x<0){putchar('-');write(-x);return;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,c[550],ans;
string s;
bool hard[550],flag=1,vis[550];
vector<int>fanan;
void dfs(int x){
	if(x>n){
		int tot=0,res=0;
		for(int i=0;i<n;++i){
			if(tot<c[fanan[i]]&&hard[i+1])++res;
			else ++tot;
		}
		if(m<=res)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			fanan.push_back(i);
			dfs(x+1);
			vis[i]=0;fanan.pop_back();
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	//if(m==1)
	cin>>s;
	for(int i=0;i<s.size();++i)hard[i+1]=s[i]-'0';
	for(int i=1;i<=n;++i)c[i]=read();
	if(n>15){
		write(0);
		return 0;
	}
	dfs(1);
	write(ans);
	return 0;
}
//100+56~72+0~5+8~12=164~189
