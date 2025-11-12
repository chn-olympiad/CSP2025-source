#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
long long ans=0;
bool vis[N];
int a[N],p[N];
int n,m;
string s;
void dfs(int u){
	if(u==n+1){
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
//			cout<<"p="<<p[i]<<" ";
//			cout<<"a[p[i]]="<<a[p[i]]<<" ";
//			cout<<"s[i-1]="<<s[i-1]<<" ";
//			cout<<"cnt="<<cnt<<" ";
//			cout<<"tot="<<tot<<" ";
//			cout<<endl;
			if(s[i-1]=='0'){
				cnt++;
				continue;
			} 
			if(a[p[i]]<=cnt)cnt++;
			else tot++;
		}
//		cout<<endl;
		if(tot>=m)ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			p[u]=i;
			dfs(u+1);
			vis[i]=false;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	bool flag=true;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=false;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(flag){
		long long x=1;
		for(int i=n;i>=2;i--){
			x*=i;
			x%=mod;
		}
		printf("%lld",x);
	}else{
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

3 2
101
1 1 2
2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
2204128

*/ 
