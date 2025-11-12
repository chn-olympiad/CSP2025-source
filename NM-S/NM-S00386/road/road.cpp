#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5;
typedef pair<int,int> pll;
int n,m,k,e[M],ne[M],w[M],h[N],c[100],a[100][N],cnt=1,idx=0,idx2=0;
int p[N];
int l[M],r[M],ww[M];
int pianshiliufen=0;
priority_queue<pll,vector<pll>,greater<pll> >pq;

int find(int x){
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

void add(int a,int b,int c){
//	e[idx]=a;
//	ne[idx]=h[b];
//	w[idx]=c;
//	h[b]=idx++;
	l[idx]=a;
	r[idx]=b;
	ww[idx++]=c;
}

void add2(int a,int b,int c){
	e[idx2]=a;
	ne[idx2]=h[b];
	w[idx2]=c;
	h[b]=idx2++;
}

void krsk(){
	while(cnt<n){
		int d=pq.top().first,x=pq.top().second;
		pq.pop();
		int L=l[x],R=r[x];
		int left=find(L),right=find(R),price=ww[x];
		if(left!=right){
			p[left]=right;
			pianshiliufen+=price;
			add2(L,R,price);
			add2(R,L,price);
			cnt++;
		}
	}
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		p[i]=i;
	memset(h,-1,sizeof h);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		pq.push({c,idx-1});
		//add(b,a,c);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	krsk();
	cout<<pianshiliufen<<endl;
	return 0;
}
