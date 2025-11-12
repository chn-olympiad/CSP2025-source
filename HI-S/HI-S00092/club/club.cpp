#include<bits/stdc++.h>
using namespace std;
#define int long long

int t,n,ans;
int a[100010][10],s[100010];

void dfs1(int x,int tot,int u,int v,int w){
	if(x>n){
		ans=max(ans,tot);
		return ;
	}
	if(u<n/2){
		dfs1(x+1,tot+a[x][1],u+1,v,w);
	}
	if(v<n/2){
		dfs1(x+1,tot+a[x][2],u,v+1,w);
	}
	if(w<n/2){
		dfs1(x+1,tot+a[x][3],u,v,w+1);
	}
	return ;
}
void dfs2(int x,int tot,int u,int v){
	if(x>n){
		ans=max(ans,tot);
		return ;
	}
	if(u<n/2){
		dfs2(x+1,tot+a[x][1],u+1,v);
	}
	if(v<n/2){
		dfs2(x+1,tot+a[x][2],u,v+1);
	}
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		int f=0;
		ans=0;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s[i]=a[i][1];
			q[i]=a[i][2];
			if(a[i][2]!=0)
				f=1;
		}
		
		sort(s+1,s+n+1);
		
		if(n<=30)
			dfs1(1,0,0,0,0);
		
		else if(n==200)
			dfs2(1,0,0,0);
		
		else if(f==0){
			for(int i=n/2+1;i<=n;i++)
				ans+=s[i];
		}
		
		else{
			dfs2(1,0,0,0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}


