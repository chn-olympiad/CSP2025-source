#include<bits/stdc++.h>
using namespace std;

const long long N = 1e4+10;

long long n,m,k,u,v,w;
long long a[20][N]={},c[20]={};
long long ans=0;
long long f[N]={};
long long get(long long x){return (f[x]=(f[x]==x? f[x]:get(f[x])));}

struct Rode{long long u,v,w;};
bool operator<(Rode a,Rode b){return (a.w>b.w);}
priority_queue<Rode> q;
void kr(){
	long long cnt=0;
	while(cnt<n-1){
		u=q.top().u , v=q.top().v , w=q.top().w , q.pop();
		if(get(u)!=get(v)){
			f[get(u)] = f[get(v)];
			ans += w;
			cnt++;
		}
	}
//	cout<<cnt<<endl;
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) f[i]=i;
	for(long long i=1;i<=m;i++) cin>>u>>v>>w , q.push({u,v,w});
//	while(q.size()){
//		cout<<q.top().u<<' '<<q.top().v<<' '<<q.top().w<<endl;
//		q.pop();
//	}

	bool temp=1;  //ÌØÊâÐÔÖÊA 
	for(long long i=1;i<=k;i++){
		cin>>c[i] , temp&=(c[i]==0);
		for(long long j=1;j<=n;j++) cin>>a[i][j] , temp&=(a[i][j]==0);
	}
	if(temp&&k!=0){cout<<0; return 0;}
	kr();
	cout<<ans;
 	return 0;
}

/*
4 4 2 
1 4 6
2 3 7
4 2 5
4 3 4 
0 0 0 0 0
0 0 0 0 0
1 1 8 2 4
100 1 3 2 4
*/
