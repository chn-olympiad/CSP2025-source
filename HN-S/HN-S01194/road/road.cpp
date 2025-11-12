#include<bits/stdc++.h>
const int INF=1e9+7;
using namespace std;
int with[10005],cut=0,c[10005],n,qwe[10005];
int ans=0;
struct edge{
	int to,w,with;
}r[1000005];
struct v{
	int cost,a[10005];
}v[16];
bool b[10005];
void dij(int x){
	queue<int>q;
	int from=with[x],go,minn=INF;
	q.push(1);
	while(!q.empty()){
		from=with[q.front()];
		minn=INF;
		b[q.front()]=1;
		ans+=qwe[q.front()];
		go=0;
		while(1){
            //cout<<r[from].to<<" "<<r[from].with<<" "<<q.front()<<"\n";
			if(r[from].w+c[q.front()]<c[r[from].to]){
                qwe[r[from].to]=r[from].w;
                //cout<<qwe[r[from].to]<<" ";
			}
			c[r[from].to]=min(r[from].w+c[q.front()],c[r[from].to]);
			from=r[from].with;
			if(from==0){
				break;
			}
		}
		for(int i=1;i<=n;i++){
            if(c[i]<minn && !b[i]){
				minn=c[i];
				go=i;
			}
		}
		if(go==0){
            return;
		}
		q.push(go);
		q.pop();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		c[i]=INF;
	}
	c[1]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cut++;
		r[cut].with=with[u];
		r[cut].to=v;
		r[cut].w=w;
		with[u]=cut;
		cut++;
		r[cut].with=with[v];
		r[cut].to=u;
		r[cut].w=w;
		with[v]=cut;
	}
	for(int i=1;i<=q;i++){
		cin>>v[i].cost;
		for(int j=1;j<=n;j++){
			cin>>v[i].a[j];
			cut++;
			r[cut].with=with[j];
			r[cut].to=n+i;
            r[cut].w=v[i].a[j];
            cut++;
			r[cut].with=with[i];
			r[cut].to=j;
            r[cut].w=v[i].a[j];
		}
	}
	dij(1);
	/*
	for(int i=1;i<=cut;i++){
        cout<<r[i].to<<" "<<r[i].w<<" "<<r[i].with<<"\n";
	}
	for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    */
	cout<<ans;
	return 0;
}

