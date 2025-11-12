#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pl tuple<int,int,int>
using namespace std;

const int N=1e4+20,M=1e6+5,MM=2e5+5;
int n,m,k,d[10],fa[N],cl,dl;
ll ans;
pl C[M],D[M];
vector<pl>A,B,ss[10];
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
ll bcj(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	ll sum=0;
	for(int i=0;i<cl;i++){
		int x=find(get<1>(C[i]));
		int y=find(get<2>(C[i]));
		if(x==y)continue;
		sum+=get<0>(C[i]),fa[x]=y;
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		A.push_back(pl(w,x,y));
	}
	sort(A.begin(),A.end());
	for(int i=0;i<k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			ss[i].push_back(pl(w,j,n+i+1));
		}
		sort(ss[i].begin(),ss[i].end());
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	ll ans=0;
	for(pl it:A){
		int x=find(get<1>(it));
		int y=find(get<2>(it));
		if(x==y)continue;
		fa[x]=y,ans+=get<0>(it);
		B.push_back(it);
	}
	for(int s=1;s<(1<<k);s++){
		ll sum=cl=0;
		for(pl it:B)C[cl++]=it;
		for(int i=0,j;i<k;i++){
			if(!(s>>i&1))continue;
			sum+=d[i],dl=0;
			for(int a=0;a<cl;a++)
				D[dl++]=C[a];
			cl=j=0;
			for(int a=0;a<dl;a++){
				while(j<ss[i].size()&&(get<0>(ss[i][j]))<=(get<0>(D[a])))
					C[cl++]=ss[i][j++];
				C[cl++]=D[a];
			}
			while(j<ss[i].size())
				C[cl++]=ss[i][j++];
		}
		sum+=bcj();
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	
	
	return 0;
}
