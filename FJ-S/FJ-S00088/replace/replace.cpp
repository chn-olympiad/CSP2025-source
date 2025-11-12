#include<bits/stdc++.h>
using namespace std;
int n,q,b,e,ans;
struct node{
	string u,v;
}a[200005];
string x,y;
bool vis[200005];
void dfs(string xi,string yi,int l,int r){
	if(vis[xi.size()]==0){
		if(l>0)dfs(x[l-1]+xi,y[l-1]+yi,l-1,r);
		if(r<x.size()-1)dfs(xi+x[r+1],yi+y[r+1],l,r+1);
		return;
	}
	for(int i=1;i<=n;i++)
		if(a[i].u==xi&&a[i].v==yi){
			ans++;
			break;
		}
	if(l>0)dfs(x[l-1]+xi,y[l-1]+yi,l-1,r);
	if(r<xi.size()-1)dfs(xi+x[r+1],yi+y[r+1],l,r+1);
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v;
		string m=a[i].u;
		vis[m.size()]=1;
	}
	while(q--){
		cin>>x>>y;
		for(int i=0;i<x.size();i++)
			if(x[i]!=y[i]){
				b=i;break;
			}
		for(int i=x.size()-1;i>=0;i--)
			if(x[i]!=y[i]){
				e=i;break;
			}
		string u="",v="";
		for(int i=b;i<=e;i++)
			u+=x[i],v+=y[i];
		ans=0;
		dfs(u,v,b,e);
		cout<<ans<<endl;
	}
	return 0;
}

