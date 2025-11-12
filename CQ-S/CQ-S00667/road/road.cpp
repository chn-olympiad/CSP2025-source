#include<bits/stdc++.h>

using namespace std;
long long c[20010],fa[20010],n,m,k,cnt1,cnt2,ans1,ans2,nm,a[20][20010];
bool vis[200010];
long long find(long long x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct eg{
	long long u,v,w;
}e1[2000010],e2[2000010],temp[2000010];
void pre(){
	for(long long i=1;i<=n+k;i++){
		fa[i]=i;
		vis[i]=0;
	}
}
bool cmp(eg x,eg y){
	return x.w<y.w;
}
long long mst(){
	cnt2=0;
	long long ans=0;
	sort(1+e1,1+cnt1+e1,cmp);
	pre();
	for(long long i=1;i<=cnt1;i++){
		long long u=e1[i].u,v=e1[i].v,w=e1[i].w;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			e2[++cnt2]={u,v,w};
			vis[u]=vis[v]=1;
			ans+=w;
		}
		if(cnt2==nm-1)break;
	}
	//cout<<ans<<endl;
	return ans;	
}
void update(){
	cnt1=0;
	for(long long i=1;i<=cnt2;i++){
		e1[++cnt1]={e2[i].u,e2[i].v,e2[i].w};
	}
	ans1=ans2;
}
int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		e1[++cnt1]={u,v,w};
		
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	nm=n;
	ans2=mst();
	//cout<<"666\n";
	update();
	
	long long ji=0;
	for(long long i=1;i<=k;i++){
		
		for(long long j=1;j<=cnt1;j++){
			temp[j]={e1[j].u,e1[j].v,e1[j].w};
		}
		for(long long j=1;j<=n;j++){
			e1[++cnt1]={i+n,j,a[i][j]};
		}
		nm++;
		
		ans2=mst();
		long long yuanji=ji;
		ji=0;
		for(int j=1;j<=k;j++){
			if(vis[n+j])ji+=c[j];
		}
		ans2+=ji;
		if(ans2<ans1){
			update();
		}else{
			cnt1-=n;
			for(long long j=1;j<=cnt1;j++){
				e1[j]={temp[j].u,temp[j].v,temp[j].w};
			}
			ji=yuanji;
			nm--;
		}
	}
	cout<<ans1;
	return 0;
} 
