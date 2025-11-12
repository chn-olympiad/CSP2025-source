#include<bits/extc++.h>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,k;
struct _{
    int u,v,w;
};
int c[11],a[11][10005];
vector<_> e;
int f[10005];
long long ans;
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
long long kru(){
    //cout<<"------kruskal------"<<endl;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(e.begin(),e.end(),[&](const _ a,const _ b){return a.w<b.w;});
    int cnt=0;
    long long sum=0;
    for(auto [u,v,w]:e){
        if(cnt==n-1)break;
        if(find(u)==find(v))continue;
        //cout<<u<<' '<<v<<' '<<w<<endl;
        f[u]=v;
        sum+=w;
        cnt++;
    }
    //cout<<"--------end--------"<<endl;
    return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
	}
	ans=kru();
	for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
	}
	for(int mask=1;mask<(1<<k);mask++){
        auto e2=e;
        long long cost=0;
        for(int _=0;_<k;_++){
            if((mask>>_)&1){
                int i=_+1;
                cost+=c[i];
                for(int u=1;u<=n;u++){
                    for(int v=u;v<=n;v++){
                        e.push_back({u,v,a[i][u]+a[i][v]});
                    }
                }
            }
        }
        int res=kru();
        //cout<<mask<<' '<<res<<' '<<cost<<endl;
        ans=min(ans,res+cost);
        e=e2;
	}
	cout<<ans;
	return 0;
}
