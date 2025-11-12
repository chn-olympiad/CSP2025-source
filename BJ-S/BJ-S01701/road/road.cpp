#include <bits/stdc++.h>
#include <map>

using namespace std;
int ans2=0,ans3=0;
bool allow[100];
int ccc[100],co=0;
int n,m,k;



struct edge{
	int u=pow(2,29),v=pow(2,29),c=pow(2,29);
}e[1200000];
bool cmp(edge a,edge b){
	return a.c<b.c;
}
int tot=0;
int fa[12000];
int ans=pow(2,29);
int find(int son){
	if(fa[son]==son)return son;
	return fa[son]=find(fa[son]);
}

void dfs () { 
	for(int i=0;i<n+k+10;i++)fa[i]=i;
	ans2=ans3;
		int cnt=0;
		for(int j=0;j<m+k*n;j++){
			int t1=find(e[j].u),t2=find(e[j].v);
			if(t1!=t2 && !(t1>n && allow[t1-n]==0) && !(t2>n && allow[t2-n]==0)){
				fa[t1]=t2;
				ans2+=e[j].c;
				cnt++;
			}
			if(cnt==n+co-1){
				ans=min(ans,ans2);
				ans2=0;
				return ;
			}
		}
	ans2=0;
}

void tr(int no){
	if(no>=k)return ;
	dfs();
	tr(no+1);
	allow[no]=1;co++;
	ans3=ans3+ccc[no];
	dfs();
	tr(no+1);
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(allow,0,sizeof(allow));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>e[i].u>>e[i].v>>e[i].c;
		tot++;
	}
	for(int i=0;i<k;i++){
		cin>>ccc[i];
		for(int j=0;j<n;j++){
			cin>>e[tot].c;
			e[tot].u=n+i;
			e[tot++].v=j+1;
		}
	}
	sort(e,e+m+k*n+1,cmp);
	ans3=0;
	dfs();
	tr(0);
	cout<<ans;
	return 0;
}
