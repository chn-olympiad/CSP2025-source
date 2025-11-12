#include<bits/stdc++.h>
using namespace std;
int father[10005],n,m,k;
long long c[15],sum;
vector<long long>s[15];
struct edge{
	int u,v;
	long long w;
	int p;
	bool operator<(const edge &it)const{
		return w>it.w;
	}
};
priority_queue<edge> q;
struct edgee{
	int to,w;
};
int find(int x){
	if(father[x]==x)return x;
	return father[x]=find(father[x]);
}
void unionn(int x,int y){
	father[find(y)]=find(x);
	return;
}
void kurskal(){
	int kk=0;
	sum=0;
	while(!q.empty()){
		int u=q.top().u;
		int v=q.top().v;
		long long w=q.top().w;
		int p=q.top().p;
		q.pop();
		if(find(u)!=find(v)){
			if(p>0){
				for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
				if(find(i)!=find(j))q.push((edge){i,j,s[p][i-1]+s[p][j-1],0});
			}
			kk++;
			sum+=w;
			unionn(u,v);
		}
		if(kk==n-1)break;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	father[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		scanf("%d %d %lld",&u,&v,&w);
		q.push((edge){u,v,w,0});
	}	
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			long long w;
			scanf("%lld",&w);
			s[i].push_back(w);	
		}
		for(int j=1;j<n;j++)
		for(int k=j+1;k<=n;k++)
		if(k!=j){
			if(c[i]==0)q.push((edge){j,k,s[i][j-1]+s[i][k-1],0});
			else q.push((edge){j,k,s[i][j-1]+c[i]+s[i][k-1],i});
		}	
	}
	kurskal();
	printf("%lld",sum);
	return 0;
}
