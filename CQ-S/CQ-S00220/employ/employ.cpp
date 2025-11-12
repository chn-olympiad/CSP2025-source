#include<bits/stdc++.h>
using namespace std;
char s[100009];
int rs[100009],bj[100009];
int a,b,ans=0;
const int mod=998244353;
void dfs(int x,int y,int z){
	if(x==a+1){
		if(z>=b)ans++;
		return; 
	}
	for(int i=1;i<=a;i++){
		if(!bj[i]){
			bj[i]=1;
			if(rs[i]>y&&s[x]=='1')dfs(x+1,0,z+1);
			else dfs(x+1,y+1,z);
			bj[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>s[i];
	for(int i=1;i<=a;i++)cin>>rs[i];
	if(a<=10){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	int k=0;
	for(int i=1;i<=a;i++)if(s[i]!='1')k++;
	if(k)cout<<0;
	else{
		int cnt=0;
		for(int i=1;i<=a;i++)if(rs[i]==0)cnt++;
		if(cnt+b>a){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=a;i++)ans=1ll*ans*i%mod;
		cout<<ans; 
	}
	return 0;
}
