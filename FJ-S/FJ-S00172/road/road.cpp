#include<bits/stdc++.h>

using namespace std;

#define int long long

struct line{
	int v,w,l=-1; 
};

bool operator<(line a,line b){
	return a.w>b.w;
}

vector<line> r[1505];
bool vi[1505];
bool c55[1500005];
int c56=0;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++){
		line c;
		int u=0;
		scanf("%lld %lld %lld",&u,&c.v,&c.w);
		c.l=c56++;
		r[u].push_back(c);
		swap(c.v,u);
		r[u].push_back(c);
	}
	
	for(int i=1;i<=k;i++){
		int r4=0;
		cin>>r4;
		for(int j=1;j<=n;j++){
			line c2;
			scanf("%lld",&c2.w);
			c2.v=j;
			c2.l=c56++;
			r[n+i].push_back(c2);
			c2.v=n+i;
			c2.w+=r4;
			r[j].push_back(c2);
		}
	}
	//cout<<wk<<";"<<ok<<endl;
	int ct=1,af=0;
	vi[1]=true;
	priority_queue<line> c2;
	for(line c:r[1]){
		c2.push(c);
	}
	while(ct<n){
		line tp=c2.top();
		c2.pop();
		if(vi[tp.v])continue;
		//cout<<"select"<<tp.v<<";"<<tp.w<<";"<<tp.l<<endl;
		af+=tp.w;
		vi[tp.v]=true;
		if(tp.v<=n)ct++;
		for(line c:r[tp.v]){
			if(!vi[c.v]&&!c55[c.l]){
				c55[c.l]=true;
				//cout<<"push"<<c.w<<endl;
				c2.push(c);
			}
		}
	}
	//cout<<"n:"<<n<<endl;
	cout<<af;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 0 5
2 1 15 15 15 1
2 15 1 1 1 15
2 1 1 15 15 15
1000 0 0 0 0 0
1000 0 0 0 0 0
*/
