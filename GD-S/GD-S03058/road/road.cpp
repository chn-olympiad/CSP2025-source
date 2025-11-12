#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool f[1005];
int c[1000005];
int q[1005][1005];
struct node{
	int u,v,w;
}s[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	sort(s+1,s+1+m,cmp);
	if(k==0){
		int sum=0;
		for(int i=1;i<=min(10000,max(m,n));i++){
			if(f[s[i].u]==0||f[s[i].v]==0){
				f[s[i].u]=1,f[s[i].v]=1;
				sum+=s[i].w;
			}
			else{
				continue;
			}
			bool qql=1;
			for(int i=1;i<=n;i++){
				if(!f[i]){
					qql=0;
					break;
				}
			}
			if(qql==1){
				cout<<sum<<"\n";
				return 0;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int mi=INT_MAX,cnt=0;
		for(int j=1;j<=n;j++){
			cin>>q[i][j];
			if(q[i][j]==0){
				f[j]=1;
				continue;
			}
			if(mi>q[i][j]){
				mi=q[i][j];
				cnt=j;
			}
		}
		f[cnt]=1;
		sum+=c[i];
		sum+=mi;
	}
	for(int i=1;i<=n;i++){
		if(f[s[i].u]==0||f[s[i].v]==0){
			f[s[i].u]=1,f[s[i].v]=1;
			sum+=s[i].w;
		}
		else{
			continue;
		}
		bool qql=1;
		for(int i=1;i<=n;i++){
			if(!f[i]){
				qql=0;
				break;
			}
		}
		if(qql==1){
			cout<<sum<<"\n";
			return 0;
		}
	}
	return 0;
}
