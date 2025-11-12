#include<bits/stdc++.h>
using namespace std;
int father[10105],n,m,k,cs[15],c[15],ct[15];
unsigned long long ans=999000000001;
struct Nd{
	int u,v,cc;
	unsigned long long w;
};
Nd eg[1100015];
int find(int xxx){
	if(father[xxx]!=xxx){
		father[xxx]=find(father[xxx]);
	}
	return father[xxx];
}
void unionn(int xxxx,int yyyy){
	father[xxxx]=yyyy;
}
bool cmp(Nd a,Nd b){
	return a.w<b.w;
}
unsigned long long kruskal(int nn){
	int cnt=0;
	unsigned long long wht=0;
	for(int i=1;i<=n+15;i++){
		father[i]=i;
	}
	for(int i=1;i<=m+k*n+1;i++){
		int ppp=find(eg[i].u),qqq=find(eg[i].v),ww=eg[i].w;
		if((ppp!=qqq)&&(cs[eg[i].cc])){
			unionn(ppp,qqq);
			wht+=ww;
			cnt++;
		}
		if(cnt==n+nn-1){
			return wht;
		}
	}
	return 999000000001;
}
void solve(int dep,int tar,int now,unsigned long long cost){
	if(dep==tar){
		unsigned long long p=kruskal(tar);
		ans=min(ans,p+cost);
		return;
	}
	if(k-now+dep<tar){
		return;
	}
	if((c[now]!=0)&&(ct[now]<1)){
	solve(dep,tar,now+1,cost);
	}
	cs[now]=1;
	solve(dep+1,tar,now+1,cost+c[now]);
	cs[now]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	cs[0]=1;
	for(int i=1;i<=m;i++){
		cin>>eg[i].u>>eg[i].v>>eg[i].w;
		eg[i].cc=0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int ord=m+(i-1)*n+j;
			cin>>eg[ord].w;
			if(eg[ord].w==0){
				ct[i]++; 
			}
			eg[ord].u=i+n;
			eg[ord].v=j;
			eg[ord].cc=i;
		}
	}
	sort(eg+1,eg+m+k*n+1,cmp);
	for(int i=0;i<=k;i++){
		solve(0,i,1,0);
	}
	cout<<ans;
	return 0;
} 
