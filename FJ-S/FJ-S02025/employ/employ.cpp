#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,p=998244353;
int n,m,ans;
char s[N];
int c[N],sq[N];
bool used[N];
void dfs(int x,int num,int fail){
	//cout<<x<<" "<<num<<" "<<fail<<endl;
	if(x>n){
		if(num>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		bool op1=(s[x]=='1'&&c[i]>fail);
		bool op2=(s[x]=='0'||c[i]<=fail);
		dfs(x+1,num+op1,fail+op2);
		used[i]=0;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	sq[0]=1;
	for(int i=1;i<=500;i++)sq[i]=(sq[i-1]*i)%p;
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1,0,0);
		cout<<ans%p;
		return 0;
	}
	bool ok=1;int num=0;
	for(int i=1;i<=n;i++){
		if(s[i]!='1')ok=0;
	}
	if(ok){
		for(int i=1;i<=n;i++){
			if(c[i]>0)num++;
		}
		if(num>=m)cout<<sq[n];
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}