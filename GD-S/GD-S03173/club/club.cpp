#include<bits/stdc++.h>
using namespace std;
long long t,n,k,d1,d2,d3,ans,p;
bool vis[222222];
struct node{
	long long a1,a2,a3;
}cc[222222];
bool cmp2(node x,node y){
	return x.a1>y.a1;
}
void dfs(int x,long long sum){
	if(x==n+1) ans=max(sum,ans);
	else{
			if(!vis[x]){				
				if(d1<k)
				{
					d1++;
					vis[x]=1;
					dfs(x+1,sum+cc[x].a1);
					vis[x]=0;
					d1--;
				}
				if(d2<k)
				{
					d2++;
					vis[x]=1;
					dfs(x+1,sum+cc[x].a2);
					vis[x]=0;
					d2--;
				}
				if(d3<k)
				{
					d3++;
					vis[x]=1;
					dfs(x+1,sum+cc[x].a3);
					vis[x]=0;
					d3--;
				}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		k=n/2;
		d1=0;d2=0;d3=0;
		p=0;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			cin>>cc[i].a1>>cc[i].a2>>cc[i].a3;
			if(cc[i].a3!=cc[i].a2) p=1;
		}
		if(p==0){
			sort(cc+1,cc+1+n,cmp2);
			for(int i=1;i<=k;i++) ans+=cc[i].a1;
			return cout<<ans,0;
		}		
		if(n<30){
			dfs(1,0);
			cout<<ans<<"\n";			
		}
		else{
			for(int i=1;i<=n;i++)
				ans+=max(cc[i].a1,max(cc[i].a2,cc[i].a3));
			cout<<ans<<"\n";
		}		
	}
}
