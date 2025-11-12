#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+10,M=2e6+10;

int n,m,k,res,e[M],ne[M],w[M],idx,h[N],dist[N];
bool st[N];
void add(int a,int b,int c){
	e[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}
int d(int x){
	memset(st,0,sizeof st);
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0,1});
	st[1]=1;
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int ver=t.second,dt=t.first;
		if(ver==x)break;
		for(int i=h[ver];~i;i=ne[i]){
			int a=e[i];
			if(dist[a]>dt+w[i]){
				dist[a]=dt+w[i];
				if(!st[a]){
					q.push({dist[a],i});
					st[a]=1;
				}
			}
		}
	}
	return dist[x];
}
int main(){
	memset(h,-1,sizeof h);
	memset(dist,0x3f,sizeof dist);
	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	d(n);
	res=dist[n];
	for(int i=2;i<=n;i++){
		if(!st[i]){
			int a=i;
			int t=0;
			for(int k=h[a];~k;k=ne[i])if(st[e[k]]&&w[k]<w[t])t=k;
			res+=w[t];
		}
	}
	cout<<res<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
