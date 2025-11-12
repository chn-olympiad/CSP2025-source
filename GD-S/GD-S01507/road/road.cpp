#include <bits/stdc++.h>
using namespace std;
long long n,k,m,t[10005][10005],c[11],b[10005],du[10005],dis[10005];	int start;int ans=0;
struct bd{
	long long v;
	long long to;
	bool operator <(const bd &other)const{
		return v<other.v;
	}
};
void dijstra(int i){
	priority_queue<bd>q;
	q.push({0,i});
	b[i]=1;
	while(!q.empty()){
		bd tou=q.top();
		q.pop();
		for(int i=1;i<=n+k;i++){
			if(t[tou.to][i] && !b[i]){
				b[i]=1;
				/*if(i>n){
					dis[i]=min(tou.v+t[tou.to][i]+c[i-n],dis[i]);
					if(dis[i]==(tou.v+t[tou.to][i]+c[i-n]) && tou.v!=start) {
						c[i-n]=0;
						dis[i]-=c[i-n];
						ans+=c[i-n];
						b[tou.to]=0;
						dis[tou.to]=0;	
					}
				} */
				dis[i]=min(tou.v+t[tou.to][i],dis[i]);
				q.push({tou.v+t[tou.to][i],i});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=1;i<=n+k;i++) dis[i]=2147483647;
	for(int i=1;i<=m;i++){
		int s,e,v;cin >>s>>e>>v;
		t[s][e]=v;
		t[e][s]=v;
		du[s]++;
		du[e]++;
	}
	for(int i=1;i<=k;i++){
		cin >>c[i];
		for(int j=1;j<=n;j++){
			int a;cin >>a;
			t[n+i][j]=a;
			t[j][n+i]=a;
			du[j]++;
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(du[i]>maxn){
			maxn=du[i];
			start=i; 
		}
	}
	dijstra(start);
	for(int i=1;i<n;i++){
		ans+=dis[i];
	}
	cout <<ans;
	return 0;
}
