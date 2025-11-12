#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k,c[10001],x,y,v,used[10001],ans,f[10001],dis[10001],l[10001],head=1,tail=1;
vector <int>a[10001],w[10001];
ll q[100001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<=10000;i++) dis[i]=100000000000;
	memset(used,0,sizeof(used));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>v;
		a[x].push_back(y);
		a[y].push_back(x);
		w[x].push_back(v);
		w[y].push_back(v);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>v;
			w[j].push_back(v);
		}
	}
	q[1]=1;used[1]=1;dis[1]=0;
	while(head<=tail){
		ll p=q[head];
		for(int i=0;i<a[p].size();i++){
			ll p1=a[p][i];
			if(p1==f[p]) continue;
			if(dis[p]+w[p][i]<dis[p1]) {
				dis[p1]=dis[p]+w[p][i];
				ans+=w[p][i]-l[p1];
				l[p1]=w[p][i];
			}
			for(int j=1;j<=k;j++) {
				if(dis[p]+w[p1][a[p1].size()-j]+w[p][a[p].size()-j]+c[k-j+1]<dis[p1]&&used[n+k-j+1]==0){
					dis[p1]=dis[p]+w[p1][a[p1].size()-j]+w[p][a[p].size()-j]+c[k-j+1];
					used[n+k-j+1]=1;
					ans+=w[p1][a[p1].size()-j]+w[p][a[p].size()-j]+c[k-j+1]-l[p1];
					l[p1]=w[p1][a[p1].size()-j]+w[p][a[p].size()-j]+c[k-j+1];
				}
				else if(dis[p]+w[p1][a[p1].size()-j]+w[p][a[p].size()-j]<dis[p1]&&used[n+k-j+1]==1){
					dis[p1]=dis[p]+w[p1][a[p1].size()-j]+w[p][a[p].size()-j];
					ans+=w[p1][a[p1].size()-j]+w[p][a[p].size()-j]-l[p1];
					l[p1]=w[p1][a[p1].size()-j]+w[p][a[p].size()-j];
				}
			}
			if(!used[p1]){
				used[p1]=1;
				q[++tail]=p1;
				f[tail]=p;
			}
		}
		head++;
	}
	cout<<ans;
}
