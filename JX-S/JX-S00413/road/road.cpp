#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e3+1,M=1e4+1; 
int ans=0;
int n,m,k;
struct edge{
	int u,v,w;  
};
edge gra[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int s[M];
int find(int x){
	if(s[x]!=x) s[x]=find(s[x]);
	return s[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>gra[i].u>>gra[i].v>>gra[i].w;
	}    
	sort(gra+1,gra+1+m,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	while(cnt<=n){
		edge top=gra[cnt];  
		int e1=find(top.u);
		int e2=find(top.v);
		if(e1!=e2){
			s[e1]=e2;
			ans+=top.w;
		
		}	
		cnt++;
	}
	cout<<ans;
	return 0;
}