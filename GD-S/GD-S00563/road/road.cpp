#include<bits/stdc++.h>
using namespace std;
int n,m,k,cntl1,now1=1,nowc=1,cntl2[15],ans,tmp[15];
int f[10024],used[15],now[15];
bool build[15],check[15];
struct node{
	int u,v,w;
}l1[1000006],l2[15][100005];
struct cost{
	int id,val;
}c[15];
bool cmp(node a,node b){
	return a.w<b.w;
}
bool cmp1(cost a,cost b){
	return a.val<b.val;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void h(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+10;i++) f[i]=i,now[i]=1;	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		l1[++cntl1]=(node){u,v,w};
	}
	if(k==0){
		sort(l1+1,l1+1+cntl1,cmp);
		for(int i=1;i<=cntl1;i++){
			if(find(l1[i].u)==find(l1[i].v)) continue;
			ans+=l1[i].w; 
			h(l1[i].u,l1[i].v);
		}
		cout<<ans;
		return 0; 
	}	
	for(int i=1;i<=k;i++){
		cin>>c[i].val;
		c[i].id=i;
		int val;
		for(int j=1;j<=n;j++){
			cin>>val;
			l2[i][++cntl2[i]]=(node){n+i,j,val};
		} 
	}
	sort(c+1,c+1+k,cmp1);
	sort(l1+1,l1+1+m,cmp);
	for(int i=1;i<=k;i++) sort(l2[i]+1,l2[i]+1+n,cmp);
	while(1){
		bool can=0;
		int Min=INT_MAX,op=0,id=0;
		for(int i=1;i<=k;i++){
			if(!build[i]||now[i]>n||find(l2[i][now[i]].u)==find(l2[i][now[i]].v)){continue;
			}
			if(Min>l2[i][now[i]].w) Min=l2[i][now[i]].w,op=1,id=i;
		}
		if(now1>m||Min<l1[now1].w||find(l1[now1].u)==find(l1[now1].v));
		else Min=l1[now1].w,op=2;
		if(nowc>k||Min<c[nowc].val);
		else Min=c[nowc].val,op=3,id=c[nowc].id;
		if(op==1){
			can=1;
			used[id]++;
			if(used[id]>1&&!check[id]) tmp[id]=0,check[id]=1;
			else tmp[id]+=l2[id][now[id]].w;
			ans+=l2[id][now[id]].w;
			h(l2[id][now[id]].u,l2[id][now[id]].v);
			now[id]++;
		}
		if(op==2){
			can=1;
			h(l1[now1].u,l1[now1].v);
			ans+=l1[now1].w;
			now1++;
		}
		if(op==3){
			can=1;
			build[id]=1;
			ans+=c[id].val;
			nowc++;
			if(!check[id]) tmp[id]+=c[id].val;
		}
		if(!can) break;
	}
	for(int i=1;i<=k;i++) if(!check[i])ans-=tmp[i];
	cout<<ans;
	return 0;
}
