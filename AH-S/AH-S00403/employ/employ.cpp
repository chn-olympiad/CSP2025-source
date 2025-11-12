#include<bits/stdc++.h>
    using namespace std;
    int a[510],b[510],vis[510];
        int n,m;
    long long cnt=0;
    void dfs(int cur,int sum,int out){
		if(cur==n+1&&sum>=m){
			cnt++;
			cnt%=998244353;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				int p=0;
				if(b[cur]==0)p=1;
				if(out>=a[i])p=1;
				dfs(cur+1,sum+(1-p),out+p);
				vis[i]=0;
			}
		}
	}
	void dfs1(int cur,int sum,int out){
		if(sum==1){
			long long g=1;
			for(int i=cur;i<=n;i++){
				g*=(n+1-i);
				g%=998244353;
			}
			cnt+=g;
			cnt%=998244353;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				int p=0;
				if(b[cur]==0)p=1;
				if(out>=a[i])p=1;
				dfs(cur+1,sum+(1-p),out+p);
				vis[i]=0;
			}
		}
	}
    int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
     for(int i=0;i<s.size();i++){
		 if(s[i]=='1')b[i+1]=1;
		 else {
			 b[i+1]=0;
		 }
	 }
	 if(m==1){
		 dfs1(1,0,0);
	 cout<<cnt;
	 return 0;
	 }
	 if(m==n){
		 int gk=0;
		 for(int i=1;i<=n;i++){
			 if(b[i]==0)gk=1;
			 if(a[i]==0)gk=1;
		 }
		 if(gk==1)cout<<0;
		 else{
			 cnt=1;
			 for(int i=1;i<=n;i++){
				 cnt*=i;
				 cnt%=998244353;
			 }
			 cout<<cnt;
		 }
		 return 0;
	 }
	 dfs(1,0,0);
	 cout<<cnt;
    return 0;
    }
