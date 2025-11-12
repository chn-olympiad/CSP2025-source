#include<bits/stdc++.h>
using namespace std;
struct ccc{
	long long f,t,w;
	bool operator > (const ccc& other)const{
		return w>other.w;
	}
}d[1100000];
long long a,s,f,j,l,n,m,k,c[11],ct[11][11000],ans,minans,t[11000];
bool bbooll;
ccc g,h;
void into(){
	for(int i=1;i<=n;i++) t[i]=i;
}
int find(int x){
	if(x==t[x]) return x;
	else{
		t[x]=find(t[x]);
		return t[x];
	}
}
bool hb(int aa,int bb){
	int ra=find(aa),rb=find(bb);
	if(ra==rb) return 0;
	else{
		t[ra]=rb;
		return 1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d[i].f>>d[i].t>>d[i].w;
	}
	if(k) bbooll=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0) bbooll=0;
		for(int j=1;j<=n;j++){
			cin>>ct[i][j];
			if(ct[i][j]>0) bbooll=0;
		}
	}
	if(bbooll){
		cout<<0;
		return 0;
	}
	if(k==0){
		into();
		priority_queue<ccc,vector<ccc>,greater<ccc> > q;
		for(int i=1;i<=m;i++){
			q.push(d[i]);
		} 
		while(q.size()>0){
			g=q.top();
			q.pop();
			if(hb(g.f,g.t)){
				ans+=g.w;
			}
		}
		cout<<ans;
	}
}
