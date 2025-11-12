#include<bits/stdc++.h>
using namespace std;
struct st{
	int u,v,w;
	friend bool operator <(st x,st y){
		return x.w<y.w;
	}
}d[2000009];
vector<st>ve;
int f[20009],g[20][20009],hf[20];
int gf(int x){
	if(f[x]!=x)f[x]=gf(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	int a,b,c;
	long long ans=1e18;
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++)cin>>d[i].u>>d[i].v>>d[i].w;
	for(int i=1;i<=a;i++)f[i]=i;
	sort(d+1,d+b+1);
	for(int i=1;i<=b;i++){
		int fx=gf(d[i].u),fy=gf(d[i].v);
		if(fx!=fy){
			ve.push_back(d[i]);
			f[fx]=fy;
		}
	}
	for(int i=1;i<=c;i++){
		cin>>hf[i];
		for(int j=1,x;j<=a;j++)cin>>g[i][j];
	}
	for(int i=0;i<(1<<c);i++){
		long long an=0;
		vector<st>t=ve;
		for(int j=1;j<=c;j++){
			if((1<<(j-1))&i){
				an+=hf[j];
				for(int k=1;k<=a;k++)t.push_back({j+a,k,g[j][k]});
			}
		}
		for(int j=1;j<=a+c;j++)f[j]=j;
		sort(t.begin(),t.end());
		for(auto i:t){
			int fx=gf(i.u),fy=gf(i.v);
			if(fx!=fy){
				an+=i.w;
				f[fx]=fy;
			} 
		}
		ans=min(ans,an);
	}
	cout<<ans;
	return 0;
} 
