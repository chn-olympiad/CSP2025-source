#include<bits/stdc++.h>
using namespace std;
struct N{
	long long x,y,w;
	friend operator <(N x,N y){
		return x.w>y.w;
	}
};
signed long long f[10010],n,m,k;
vector<N>v;
signed long long a[11][10010],d[11];
signed long long ma=INT_MIN;
signed long long find(signed long long x){
	if(f[x]==x){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
signed long long mi[11];
priority_queue<N>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		signed long long x,y,z;
		cin>>x>>y>>z;
		q.push({x,y,z});
		ma=max(ma,z);
	}
	for(int i=1;i<=k;i++){
		cin>>d[i];
		mi[i]=LLONG_MAX;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			mi[i]=min(mi[i],a[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		if(d[i]+mi[i]>=ma){
			continue;
		}
		for(int j=1;j<n;j++){
			for(int w=j+1;w<=n;w++){
				q.push({j,w,a[i][j]+a[i][w]+d[i]});
			} 
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	signed long long ans=0;
	signed long long cnt=0;
	while(!q.empty() && cnt<n-1){
		N x=q.top();
		q.pop();
		signed long long nx=find(x.x),ny=find(x.y);
		if(nx==ny){
			continue;
		}
		cnt++;
		ans+=x.w;
		f[nx]=ny;
	}
	cout<<ans<<endl;
	return 0;
}
