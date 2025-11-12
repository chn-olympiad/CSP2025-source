#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e6+10;
struct node{
	long long u,v,w;
	friend bool operator<(node a,node b){
		return b.w<a.w;
	}
};
long long n,m,k,c[20],a[20][maxn],tj1,f[maxn],cnt=1,ans;
bool pc[maxn];
priority_queue<node>ed;
long long find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void merge(long long a,long long b){
	int ra=find(a),rb=find(b);
	if(ra!=rb){
		f[ra]=rb;
		cnt++;
	}
}
void solve1(){
	cout<<0;
	return ;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		ed.push({u,v,w});
		ed.push({v,u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		tj1=max(tj1,c[i]);
		for(int j=1;j<=n;j++){
			f[j]=j;
			cin>>a[i][j];
			tj1=max(tj1,a[i][j]);
		}
	}
	if(tj1==0&&k!=0){
		solve1();
		return ;
	}
	while(cnt<n&&!ed.empty()){
		long long u=ed.top().u,v=ed.top().v,w=ed.top().w;
		//cout<<u<<" "<<v<<" "<<w<<"QAQ"<<endl;
		ed.pop();
		if(find(u)==find(v))continue;
		long long t=1e9,pos;
		bool boo=0;
		for(int i=1;i<=k;i++){
			long long effort=find(v),hard=find(u);
			for(int j=1;j<=n;j++){
				if(find(j)==effort){
					if(pc[i])t=min(t,a[i][u]+a[i][j]);
					else if(t>=a[i][u]+a[i][j]+c[i]){
						boo=1;
						t=a[i][u]+a[i][j]+c[i];
						pos=i;
					}	
				}
			}
			for(int j=1;j<=n;j++){
				if(find(j)==hard){
					if(pc[i])t=min(t,a[i][v]+a[i][j]);
					else if(t>=a[i][v]+a[i][j]+c[i]){
						boo=1;
						t=a[i][v]+a[i][j]+c[i];
						pos=i;
					}	
				}
			}
		}
		if(t<=w){
			ans+=t;
			if(boo)pc[pos]=1;
			//cout<<u<<" "<<v<<"qaq"<<endl;
		}else{
			ans+=w;
			//cout<<u<<" "<<v<<"QAQ"<<endl;
		}
		merge(u,v);
	}
	//for(int i=1;i<=k;i++)cout<<pc[i]<<" ";
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long T=1;
	while(T--){
		solve();
	}
	return 0;
}
