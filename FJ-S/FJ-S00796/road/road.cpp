#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,b,c,d,e,f,g,h;
struct bi{
	int x,y,val;
	bool operator <(const bi &other)const{
		return val<other.val;
	} 
}s[4000005];
int cnt=0;
int p[20];
int w[1000100];
void add(int x,int to,int val){
	s[++cnt].x=x;
	s[cnt].y=to;
	s[cnt].val=val;
}
struct zt{
	int x,val,state;
	bool operator <(const zt & other) const{
		return val<other.val;
	}
};
int find(int x){
	if(w[x]==x)return x;
	return w[x]=find(w[x]);
}
int sta[1<<11];
vector<bi> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	s[0].val=0;
	s[0].y=0;
	s[0].x=0;
	q.push_back(s[0]);
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
		q.push_back(s[cnt]);
		add(b,a,c);
		q.push_back(s[cnt]);
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			add(1e4+5+i,j,a);
			add(j,1e4+5+i,a);
			q.push_back(s[cnt]);
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<k;j++){
			if((i>>j)&1)sta[i]+=p[j+1];
		}
	}
	ll daan=0x7ffffff,ans=0;
	sort(s+1,s+1+cnt);
	for(int i=0;i<(1<<k);i++){
		int cs=1;int nn=1;ans=0;
		bool v[100000];
		memset(v,0,sizeof(0));
		for(int l=0;l<k;l++){
			if((i>>l)&1)v[l+1]=1;
		}
		for(int i=1;i<=1e5+10;i++){
			w[i]=i;
		}
		while(cs<n){
			if(find(s[nn].x)!=find(s[nn].y)){
				if(s[nn].y>=1e4+5&&!v[(s[nn].y-10004)]){
					nn++;continue;
				}
				if(q[nn].x>=1e4+5&&!v[q[nn].x-10004]){
					nn++;
					continue;
				}
				w[find(q[nn].x)]=find(q[nn].y);
				cs++;
				ans+=q[nn].val;
				nn++; 
			}
		}
		daan=min(daan,ans);
	}
	cout<<daan;
}
