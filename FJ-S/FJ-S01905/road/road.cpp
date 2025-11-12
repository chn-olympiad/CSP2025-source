#include<bits/stdc++.h>
using namespace std;
int n,m,k,root[2000010],cnt=0,cff[12],mon[12][10010];
bool xf[12][10010];
vector<pair<int,int> > ve[10010];
long long ans=0;
struct node{
	int fr,too,va;
}edge[2000010];
bool cmp(node aa,node bb){
	return aa.va<bb.va;
}
int findd(int d){
	if(root[d]==d) return d;
	root[d]=findd(root[d]);
	return root[d];
}

/*
void outt(node aa){
	cout<<aa.fr<<" "<<aa.too<<" "<<aa.va<<"\n";
}*/
void work14(){
	for(int i=1;i<=m;i++) scanf("%d%d%d",&edge[i].fr,&edge[i].too,&edge[i].va);
	for(int i=1;i<=k;i++){
		int c,va;
		scanf("%d",&c);
		//if(c!=0) cout<<"*";
		for(int f=1;f<=n;f++){
			scanf("%d",&va);
			m++;edge[m].fr=i,edge[m].too=f,edge[m].va=c+va;
			//outt(edge[m]);
		}
	}
	sort(edge+1,edge+1+m,cmp);
	//cout<<m<<endl;
	//cout<<edge[m].va<<endl;
	for(int i=1;i<=n;i++) root[i]=i;
	for(int i=1;i<=m;i++){
		int xx1=findd(edge[i].fr),xx2=findd(edge[i].too);
		if(xx1==xx2) continue;
		++cnt,ans=ans+edge[i].va,root[xx1]=xx2;
		if(cnt==n-1) break;
	}
	printf("%lld",ans);
}
void worka(){
	for(int i=1;i<n;i++){
		pair<int,int> zdd;
		zdd.second=2147483647;
		int xx1=findd(i);
		for(auto f:ve[i]){//正常修路所需要的最小值zdd 
			int xx2=findd(f.first);
			if(xx1!=xx2){
				zdd=f;
				break;
			}
		}
		int minva=2147483647,minto,zzh;
		for(int f=1;f<=n;f++){//算出用城镇化的值
			int xx2=findd(f);
			if(xx1==xx2) continue;
			for(int j=1;j<=k;j++){
				int gbj=0;
				if(!xf[j][i]){
					gbj=gbj+mon[j][i];
					//if(j==1 and i==3) cout<<"/";
				}
				if(!xf[j][f]) gbj=gbj+mon[j][f];
				if(gbj<minva){
					minto=f;
					minva=gbj;
					zzh=j;
					//if(i==3) cout<<"*"<<minto<<" "<<minva<<" "<<zzh<<"\n";
				}
			}
		}
		if(minva<zdd.second){
			ans=ans+minva;
			root[xx1]=minto;
			xf[zzh][i]=xf[zzh][minto]=true;
			//cout<<ans<<" "<<minto<<" "<<minva<<" "<<zzh<<" "<<"\n";
		}else{
			ans=ans+zdd.second;
			root[xx1]=zdd.first;
			//cout<<ans<<" "<<zdd.first<<" "<<zdd.second<<"\n";
		}
	}
	printf("%lld",ans);
}
bool shifou[12];
long long checkk(){
	long long chans=0;
	for(int i=1;i<n;i++){
		pair<int,int> zdd;
		zdd.second=2147483647;
		int xx1=findd(i);
		for(auto f:ve[i]){//正常修路所需要的最小值zdd 
			int xx2=findd(f.first);
			if(xx1!=xx2){
				zdd=f;
				break;
			}
		}
		int minva=2147483647,minto,zzh;
		for(int f=1;f<=n;f++){//算出用城镇化的值
			if(!shifou[f]) continue;
			int xx2=findd(f);
			if(xx1==xx2) continue;
			for(int j=1;j<=k;j++){
				int gbj=0;
				if(!xf[j][i]){
					gbj=gbj+mon[j][i];
					//if(j==1 and i==3) cout<<"/";
				}
				if(!xf[j][f]) gbj=gbj+mon[j][f];
				if(gbj<minva){
					minto=f;
					minva=gbj;
					zzh=j;
					//if(i==3) cout<<"*"<<minto<<" "<<minva<<" "<<zzh<<"\n";
				}
			}
		}
		if(minva<zdd.second){
			chans=chans+minva;
			root[xx1]=minto;
			xf[zzh][i]=xf[zzh][minto]=true;
			//cout<<ans<<" "<<minto<<" "<<minva<<" "<<zzh<<" "<<"\n";
		}else{
			chans=chans+zdd.second;
			root[xx1]=zdd.first;
			//cout<<ans<<" "<<zdd.first<<" "<<zdd.second<<"\n";
		}
	}
	return chans;
}
void dfs(int d,int h){
	if(d>k){
		ans=min(ans,h+checkk());
		for(int i=1;i<=n;i++){
			root[i]=i;
			for(int f=1;f<=k;f++) xf[i][f]=false;
		}
		return;
	}
	dfs(d+1,h);
	shifou[d]=true;
	dfs(d+1,h+cff[d]);
	shifou[d]=false;
}
void workall(){
	ans=(1ll<<62);
	dfs(1,0);
	printf("%lld",ans);
}
void workk(){
	bool flagworka=true;
	int fr,too,va;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&fr,&too,&va);
		ve[fr].push_back({too,va});
		ve[too].push_back({fr,va});
	}
	for(int i=1;i<=n;i++){
		root[i]=i;
		sort(ve[i].begin(),ve[i].end(),greater<pair<int,int>>());
	}
	//cout<<ve[2][0].first<<"*";
	for(int i=1;i<=k;i++){
		scanf("%d",&cff[i]);
		if(cff[i]) flagworka=false;
		//if(c!=0) cout<<"*";
		for(int f=1;f<=n;f++){
			scanf("%d",&mon[i][f]);
		}
	}
	if(flagworka) worka();
	else workall();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0) work14();
	else workk();
	return 0;
}
