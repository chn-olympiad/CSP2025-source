#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],ans;
long long dis[100];
bool vis[100005];
void dfs(int k,int x,int y,int z,long long sum){
	if(k>n){
		if(x<=n/2&&y<=n/2&&z<=n/2){
			ans=max(ans,sum);
		}
		return ;
    }
    if(!(x<=n/2&&y<=n/2&&z<=n/2)){
		return ;
	}
    dfs(k+1,x+1,y,z,sum+a[k]);
    dfs(k+1,x,y+1,z,sum+b[k]);
    dfs(k+1,x,y,z+1,sum+c[k]);
}
long long try_b(){
	for(int i=1;i<=n;i++){
		ans+=max(a[i],b[i]);
    }
	return ans;
}
long long try_a(){
	sort(a+1,a+1+n);
	for(int i=n;i>=n/2;i--){
		ans+=a[i];
	}
	return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
		cin>>n;
		memset(vis,0,sizeof(vis));
		bool ob=1,oc=1,op=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) ob=0;
			if(c[i]!=0) oc=0;
			if(vis[a[i]]==1||vis[b[i]]==1||vis[c[i]]==1){
				op=0;
			}
			vis[a[i]]=1,vis[b[i]]=1,vis[c[i]]=1;
		}
		if(op==1){
	        for(int i=1;i<=n;i++){
			    ans+=max(a[i],max(b[i],c[i]));
		    }
		    cout<<ans<<"\n";
		    continue;
	    }
	    if(n<=16){
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
	    }
	    if(ob==1&&oc==1){
			cout<<try_a()<<"\n";
			continue;
		}
		if(oc==1){
			cout<<try_b()<<"\n";
	    }
	}
}
