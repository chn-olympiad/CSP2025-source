#include<bits/stdc++.h>
using namespace std;

long long t,n,ans,v[10];
struct ss{
	long long a,b,d;
}s[100005];

void dfs(long long x,long long y){
	if(x==n){
		ans=max(ans,y);
		return ;
	}	
	if(v[1]+1<=n/2){
		v[1]++;
		dfs(x+1,y+s[x+1].a);		
		v[1]--;
	}
	if(v[2]+1<=n/2){
		v[2]++;
		dfs(x+1,y+s[x+1].b);		
		v[2]--;
	}
	if(v[3]+1<=n/2){
		v[3]++;
		dfs(x+1,y+s[x+1].d);		
		v[3]--;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b>>s[i].d;
		dfs(0,0);
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}
