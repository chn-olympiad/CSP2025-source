#include<bits/stdc++.h>
using namespace std;
const int MAXN=10020;
const int MAXM=2020010;
int h[MAXN],nxt[MAXM],go[MAXM],w[MAXM],cnt=0,n,m,k;
void ljb(int x,int y,int v){
	nxt[++cnt]=h[x];
	h[x]=cnt;
	go[cnt]=y;
	w[cnt]=v;
}
bool vs[MAXN];
int zxscs(){
	//cout<<1<<endl;
	priority_queue<pair<int,pair<int,int> >,
	               vector<pair<int,pair<int,int> > >,
	               greater<pair<int,pair<int,int> > > >hp;
	//cout<<1<<endl;
	int r=h[1],nm=n,res=0;
	//cout<<1<<endl;
	while(r!=0){
		hp.push(make_pair(w[r],make_pair(1,go[r])));
		r=nxt[r];
		//cout<<1<<endl;
	}
	vs[1]=1;
	//cout<<1<<endl;
	while(nm>1){
		pair<int,pair<int,int> >u=hp.top();
		hp.pop();
		//cout<<1<<endl;
		while(vs[u.second.second]){
			u=hp.top();
			hp.pop();
			//cout<<u.second.second<<endl;
		}
		vs[u.second.second]=1;
		res+=u.first;
		nm--;
		r=h[u.second.second];
		while(r!=0){
			hp.push(make_pair(w[r],make_pair(u.second.second,go[r])));
			r=nxt[r];
			//cout<<1<<endl;
		}
		//cout<<u.second.second<<endl;
	}
	return res;
}
int main(){
	int i;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ljb(u,v,w);
		ljb(v,u,w);
	}
	//cout<<1<<endl;
	cout<<zxscs();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
