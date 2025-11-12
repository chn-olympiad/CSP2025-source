#include<bits/stdc++.h>
using namespace std;
const int N=500+7;
const int mod=998244353;
#define ll long long
#define pii pair<int,int> 
#define fir first
#define sec second
#define mkpir make_pair

//void opened(){
//}

int c[N];
int n,m;
ll ans=0;
string s;
int de[N];
bool vis[N];

void dfs(int dep,int get){
	
	if(dep==n){
		if(get>=m){
			
//			for(int i=0;i<dep;i++){
//				cout<<de[i]<<" ";
//			}
//			cout<<endl;
			
			ans++;
			ans%=mod;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			de[dep]=i;
			if(s[dep]=='0'){
				vis[i]=true;
				dfs(dep+1,get);
				vis[i]=false;
			}else{
				if(dep-get<c[i]){
					vis[i]=true;
					dfs(dep+1,get+1);
					vis[i]=false;
				}else{
					vis[i]=true;
					dfs(dep+1,get);
					vis[i]=false;
				}
			}
			
				
		}
	}
	
}

int main(){
//	opened();
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	
	bool flag=true; 
	cin>>n>>m;
	cin>>s;
	
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(s[i]=='0')flag=false;
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		flag=false;
	}
	
	if(n==m){
		if(!flag)cout<<0;
		else{
			
			ll ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
		}
		return 0;
	} 
	if(flag){
		
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	
	dfs(0,0);
	
	cout<<ans;
	
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3



*/
