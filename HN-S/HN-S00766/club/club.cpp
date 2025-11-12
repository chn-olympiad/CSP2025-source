#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1e4;
struct node{
	long long num,cnt,flag;
};
bool vis[maxn];
node a[maxn],b[maxn],c[maxn];
bool cmp(node x,node y){return x.num>y.num;}
long long add(int x){
	//vis,ÊÇ·ñÓÃ¹ý£¿ 
	if(a[x].cnt!=b[x].cnt&&b[x].cnt!=c[x].cnt&&a[x].cnt!=c[x].cnt){
		if(vis[a[x].cnt]&&vis[b[x].cnt]&&vis[c[x].cnt]) return 0;
		else if(!vis[a[x].cnt]&&vis[b[x].cnt]&&vis[c[x].cnt]) return a[x].num;
		else if(vis[a[x].cnt]&&!vis[b[x].cnt]&&vis[c[x].cnt]) return b[x].num;
		else if(vis[a[x].cnt]&&vis[b[x].cnt]&&!vis[c[x].cnt]) return c[x].num;
		else if(!vis[a[x].cnt]&&!vis[b[x].cnt]&&vis[c[x].cnt]) return a[x].num+b[x].num;
		else if(!vis[a[x].cnt]&&vis[b[x].cnt]&&!vis[c[x].cnt]) return a[x].num+c[x].num;
		else if(vis[a[x].cnt]&&!vis[b[x].cnt]&&!vis[c[x].cnt]) return b[x].num+c[x].num;
		else if(!vis[a[x].cnt]&&!vis[b[x].cnt]&&!vis[c[x].cnt]) return a[x].num+b[x].num+c[x].num;
	}
	else if(a[x].cnt!=c[x].cnt||b[x].cnt!=c[x].cnt||a[x].cnt!=b[x].cnt){
		if(vis[a[x].cnt]&&vis[b[x].cnt]&&vis[c[x].cnt]) return 0;
		int tmp1,tmp2;
		if(a[x].flag!=-1){
			if(vis[a[x].cnt]||vis[b[x].cnt]&&vis[c[x].cnt]) return 0;
			else if(!vis[b[x].cnt]) return a[x].num+b[x].num;
			else if(!vis[c[x].cnt]) return a[x].num+c[x].num;
			else if(!vis[a[x].cnt]) return a[x].num;
		}
		else if(b[x].flag!=-1){
			if(vis[b[x].cnt]||vis[a[x].cnt]&&vis[c[x].cnt]) return 0;
			else if(!vis[a[x].cnt]) return a[x].num+b[x].num;
			else if(!vis[c[x].cnt]) return b[x].num+c[x].num;
			else if(!vis[b[x].cnt]) return b[x].num;
		}
		else if(c[x].flag!=-1){
			if(vis[c[x].cnt]||vis[a[x].cnt]&&vis[b[x].cnt]) return 0;
			else if(!vis[a[x].cnt]) return b[x].num+c[x].num;
			else if(!vis[b[x].cnt]) return a[x].num+c[x].num;
			else if(!vis[c[x].cnt]) return c[x].num;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].cnt=i,b[i].cnt=i,c[i].cnt=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].cnt==b[i].cnt&&b[i].cnt==c[i].cnt) a[i].flag=-1,b[i].flag=-1,c[i].flag=-1;
			else if(a[i].cnt==b[i].cnt) a[i].flag=-1,b[i].flag=-1;
			else if(a[i].cnt==c[i].cnt) a[i].flag=-1,c[i].flag=-1;
			else if(b[i].cnt==c[i].cnt) b[i].flag=-1,c[i].flag=-1;
		}
		long long ans=0;
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			ans+=add(i);
			vis[a[i].cnt]=true;
			vis[b[i].cnt]=true;
			vis[c[i].cnt]=true;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
