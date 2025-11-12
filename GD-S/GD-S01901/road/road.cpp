#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+4;
int n,m,k,f[N],h[N],ans,cnt;
struct stu{
	int s,to,w;
};
vector<stu> v;
bool cmp(stu a,stu b){
	return a.w<b.w;
}
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	if(h[x]<h[y]){
		f[x]=y;
	}else if(h[x]>h[y]){
		f[y]=x;
	}else{
		f[x]=y;
		h[y]++;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	for(int i=1;i<=k;i++){
		int c,a;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n;i++) f[i]=i,h[i]=1;
	if(k==0){
		for(int i=0;i<m;i++){
			if(cnt==n-1) break;
			int x=v[i].s,y=v[i].to,w=v[i].w;
			int xx=find(x),yy=find(y);
			if(xx==yy) continue ;
			merge(xx,yy);
			ans+=w;
			cnt++;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
