#include<bits/stdc++.h>
using namespace std;
struct egg{
	int v,w=0x3f3f3f3f;
}d[20005];//接收 
struct eggg{
	int u,v,w;
}e[200005];
int u,v,w,n,m,k,a[10005][11],c[105],vis[105],du[20005],ma[15],ma2[15],mid[15],mid2[15];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
		e[i+n]={v,u,w};
	}
	memset(ma,0x3f,sizeof(ma));
	memset(ma2,0x3f,sizeof(ma2));
	memset(mid,0x3f,sizeof(mid));
	memset(mid2,0x3f,sizeof(mid2));
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			if(a[j][i]<ma[i]){
				ma2[i]=ma[i];
				mid2[i]=mid[i];
				ma[i]=a[j][i];
				mid[i]=j;
			}
			else
			if(a[j][i]<
			ma2[i]){
				ma2[i]=a[j][i];
				mid2[i]=j;
			}
		}
//		cout<<ma[i]<<" "<<mid[i]<<" "<<ma2[i]<<" "<<mid2[i]<<"\n";
	}
	for(int i=1;i<=n;i++) d[i].w=0x3f3f3f3f;
	for(int i=1;i<=n*2;i++){
		u=e[i].u;
		v=e[i].v;
		w=e[i].w;
		if(d[v].v==u) continue;
		if(d[u].w>w){
			if(d[u].w==0x3f3f3f3f){
				d[u].w=0;
				du[v]++;
				du[u]++;
			}
			else{
				du[d[u].v]--;
				du[v]++;
			}
			ans=ans+w-d[u].w;
			d[u].w=w;
			d[u].v=v;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(du[d[j].v]>=2){
				if(a[j][i]==ma[i]){
					if(a[j][i]-c[i]*(vis[i]-1)+ma2[i]<=d[j].w){
						du[d[j].v]--;
						du[mid2[i]]++;
						ans=ans-d[j].w+a[j][i]-c[i]*(vis[i]-1)+ma2[i];
						d[j].v=mid2[i];
						d[j].w=a[j][i]-c[i]*(vis[i]-1)+ma2[i];
						vis[i]=1;
					}
				}
				else{
					if(a[j][i]-c[i]*(vis[i]-1)+ma[i]<=d[j].w){
						du[d[j].v]--;
						du[mid[i]]++;
						ans=ans-d[j].w+a[j][i]-c[i]*(vis[i]-1)+ma[i];
//						cout<<d[j].w<<" "<<a[j][i]-c[i]*(vis[i]-1)+ma[i]<<" ";
						d[j].v=mid[i];
						d[j].w=a[j][i]-c[i]*(vis[i]-1)+ma[i];
						vis[i]=1;
					}
				}
			}
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}//bbbbbbbbbbbbbbbbbbb