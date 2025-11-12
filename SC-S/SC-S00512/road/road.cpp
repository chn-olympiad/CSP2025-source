#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,ans=1e18,sum,cs=1,a[10004],cnt,s,an[15],minn=1e18,minnn;
struct node{
	long long v,w;
};
struct yy{
	long long a,b;
}lhy[15][10005],_[100005];
bool cmp(yy a,yy b){
	return a.a<b.a;
}
bool b[10004],f,f2,used[10004];
vector<node>e[1000006];
vector<node>new_e[1000006];
void dfs(long long fa,long long v){
	if(cs==m){f=1;if(sum<=ans)ans=min(ans,sum),f2=1,memset(new_e,0,sizeof(new_e));return;}
	for(auto ed:e[v]){
		int vv=ed.v,ww=ed.w;
		if(vv==fa||b[vv])continue;
		b[vv]=1;
		sum+=ww;
		cs++;
		dfs(v,vv);
		if(f2)new_e[v].push_back({vv,ww}),new_e[vv].push_back({v,ww});
		if(f)b[vv]=0,cs--,sum-=ww;
		if(cs==1)f=0;
	}
}
void dfs1(long long fa,long long v){
	if(cs==m){f=1;if(sum<=ans)ans=min(ans,sum);return;}
	for(auto ed:new_e[v]){
		int vv=ed.v,ww=ed.w;
		if(vv==fa||b[vv])continue;
		b[vv]=1;
		sum+=ww;
		cs++;
		dfs(v,vv);
		if(f)b[vv]=0,cs--,sum-=ww;
		if(cs==1)f=0;
	}
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(long long i=1;i<=n;i++){
		f=0;
		b[i]=1;
		dfs(0,i);
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(auto ed:new_e[i])
			a[i]+=ed.w
//			,cout<<ed.w<<" "
			;
//		cout<<"\n"<<i<<" "<<a[i]<<"\n";
		s+=a[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>lhy[i][j].a,lhy[i][j].b=i;
	}
	for(int i=1;i<=k;i++){
		if(lhy[i][0].a>s)continue;
		sort(lhy[i]+1,lhy[i]+n+1,cmp);
		for(int j=1;j<=n;j++){
			cnt=0,minn=1e18,minnn=0;
			if(a[lhy[i][j].b]>=lhy[i][j].a){_[++cnt]=lhy[i][j];if(a[lhy[i][j].b]<=minn)minn=a[lhy[i][j].b],minnn=lhy[i][j].b;}
			if(cnt>=2){
				for(int k=1;k<=cnt;k++){
					b[_[k].b]=1;
					new_e[10000+k].push_back({_[k].b,lhy[i][j].a});
					new_e[_[k].b].push_back({10000+k,lhy[i][j].a});
				}
				b[minnn]=0;
			}
			for(long long i=10001;i<=10000+cnt;i++){
				f=0;
				if(b[i])continue;
				b[i]=1;
				dfs1(0,i);
				b[i]=0;
			}
//			if(!used[i]&&max(a[lhy[i][j].b],a[lhy[i][j+1].b])>lhy[i][j].a+lhy[i][j+1].a+lhy[i][0].a)an[i]+=lhy[i][j].a+lhy[i][j+1].a+lhy[i][0].a;
//			if(max(a[lhy[i][j].b],a[lhy[i][j+1].b])>lhy[i][j].a+lhy[i][j+1].a)an[i]+=lhy[i][j].a+lhy[i][j+1].a;
		}
	}
//	for(long long i=10001;i<=10000+cnt;i++){
//		f=0;
//		if(b[i])continue;
//		b[i]=1;
//		dfs1(0,i);
//		b[i]=0;
//	}
	cout<<ans;
	return 0;
}