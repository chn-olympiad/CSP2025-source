/*
3 2 
101
1 1 2
*/
#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL ans=1;
string s;
int n,m,ff=0,mod=998244353,cnt;
const int N=1e5+5;
int a[N],f[N],b[N];

void dfs(int x){
	if(x>n){
		int num=0;
		for(int i=1;i<=n;i++){
//			cout<<a[b[i]]<<" "<<b[i]<<" "<<num<<endl;
			if(s[i]=='0'||num>=a[b[i]]) num++;
		}
//		cout<<endl;
		if(n-num>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		b[x]=i;
		f[i]=1;
		dfs(x+1); 
		f[i]=0;
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i]) cnt++;
	}
	LL len=s.size();
	s='1'+s;
	for(int i=1;i<=len;i++){
		if(s[i]=='0'){
			ff=1;
			break;
		}
	}
	if(n-cnt>=m){
		if(!ff){
			for(int i=1;i<=n;i++){
				ans*=(long long)i;
				ans%=mod;
			}
			cout<<ans;
		}
		else{
			dfs(1);
			cout<<ans;
		}
	}
	else cout<<0;	
	
	return 0;
}
