#include <bits/stdc++.h> 
using namespace std;

long long read(){
	char c=getchar();
	bool f=0;
	long long o=0;
	while(!isdigit(c)){
		f|=c=='-';
		c=getchar();
	}while(isdigit(c)){
		o=o*10+(c-'0');
		c=getchar();
	}
	return f?-o:o;
}

pair<int,pair<int,int> > e;

const long long N=10009,M=1000020;
int us[N],n,m,k,ts,te,tw,coun[15][N],ua,ub;
long long btn=0,btc=0,mx=0x3f3f3f3f3f3f3f3f;
bool boot[15];
priority_queue<pair<int,pair<int,int> > > edge,nw,bf,bf1;  

int find(int a){
	return us[a]==a?a:us[a]=find(us[a]);
}

bool kruskal(int t){
	long long tsum=btc+coun[t][0];
	if(tsum>=mx) return 0;
	int road=0;
	for(int i=1;road<n+btn-1;i++){
	auto t=nw.top();
	nw.pop();
	ts=t.second.first;
	te=t.second.second;
	ua=find(ts);ub=find(te);
	if(ua==ub) continue;
	road++;
	tw=-t.first;
	//cout<<tw<<ts<<te<<'\n';
	us[ts]=us[te];
	tsum+=tw;
	if(tsum>=mx) return 0;
	}
	if(tsum<mx){
		btn++;
		boot[t]=1;
		btc+=coun[t][0];
		mx=tsum;
		return 1;
	}
	return 0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ts=read();
		te=read();
		tw=read();
		edge.push({-tw,{ts,te}});
		edge.push({-tw,{te,ts}});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			coun[i][j]=read();
		}
	}
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n+11;j++){
			us[j]=j;
		}
		nw=edge;
		if(i){
		for(int j=1;j<=n;j++){
			nw.push({-coun[i][j],{j,n+i}});
			bf.push({-coun[i][j],{j,n+i}});
		}
		}
		//cout<<edge.size()<<nw.size()<<bf.size()<<'\n';
		if(kruskal(i)){
			while(!bf.empty()){edge.push(bf.top());
			bf.pop();}
		}
	}
	cout<<mx;
	return 0;
}
