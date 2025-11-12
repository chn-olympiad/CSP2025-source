#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,b[510],flagA=1,cnt0;
int used[510],ans,c[20];
char a[510];
void dfs(int now,int num,int num0,int cnt){
	if(cnt==n){
//		cout<<now<<" "<<num<<" "<<num0<<" "<<cnt<<endl;
		if(num>=m)ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		if(b[i]<=num0||a[cnt+1]=='0')dfs(i,num,num0+1,cnt+1);
		else dfs(i,num+1,num0,cnt+1);
		used[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a+1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(a[i]==0)flagA=0;
		cnt0+=(b[i]==1?0:1);
	}
	if(n<=10){
		dfs(0,0,0,0);
		cout<<ans;
		return 0;
	}
	if(flagA){
		int num=1;
		if(m>n-cnt0){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			(num*=i)%=mod;;
		}
		cout<<num%mod;
		return 0;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

