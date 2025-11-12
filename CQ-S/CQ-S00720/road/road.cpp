#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m,k,u,v,w,zwf,ak0;
vector<pair<long long,long long>> r[N];
long long d[15][N];
long long dis[10010];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch>'9'&&ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		r[u].push_back({v,w});
		r[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		long long cj;
		cj=read();
		d[i][1]=cj;
		for(int j=1;j<=n;j++){
			zwf=read();
			d[i][j+1]=zwf;
		}
	}
//	if(k==0){
		for(int i=1;i<=n;i++)dis[i]=LONG_LONG_MAX;
		q.push({0,1});
		dis[1]=0;
		while(!q.empty()){
			long long x=q.top().first,d=q.top().second;
			q.pop();
			for(int i=0;i<r[d].size();i++){
				 if(dis[r[d][i].first]>r[d][i].second){
				 	dis[r[d][i].first]=r[d][i].second;
				 }q.push({r[d][i].second,r[d][i].first});
			}
		}
		for(int i=1;i<=n;i++){
			cout<<dis[i]<<" ";
		}
//	}
	return 0;
}
