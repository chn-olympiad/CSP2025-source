#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt=1,ans=0;
struct node{
	int u,v,w,c;
	bool flag;
}dui[1001000];
int father[1001000];
int size=0;
void up(int x){
	if(x==1)return;
	else if(dui[x/2].w>dui[x].w){
		swap(dui[x/2],dui[x]);
		up(x/2);
	}
}
void down(int x){
	if(x*2>size&&x)return; 
	else if(dui[x*2].w<dui[x].w){
		swap(dui[x*2],dui[x]);
		down(x*2);
	}
	else if(x*2+1>size&&x)return; 
	else if(dui[x*2+1].w<dui[x].w){
		swap(dui[x*2+1],dui[x]);
		down(x*2+1);
	}
}
void add(int c,int u,int v,int w){
	dui[++size].c=c;
	dui[size].u=u;
	dui[size].v=v;
	dui[size].w=w;
	up(size);
}
void remove(int x){
	swap(dui[x],dui[size--]);
	down(x);
}
int find(int x){
	if(father[x]==x)return x;
	//cout<<666;
	father[x]=find(father[x]);
	return father[x];
}
bool check(int x,int y){
	if(find(x)==find(y))return true;
	return false;
}
void lian(int x,int y){
	//if(!check(x,y))return;
	//cout<<666;
	father[x]=y;
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		father[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(0,u,v,w);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			add(c,j,n+i,w);
		}
	}
	cout<<size<<endl;
	for(int i=1;i<=size;i++){
		cout<<dui[i].c<<' '<<dui[i].u<<' '<<dui[i].v<<' '<<dui[i].w<<endl;
	}
	while(cnt!=n){
		//cout<<666;
		if(!check(dui[1].u,dui[1].v)){
			lian(dui[1].u,dui[1].v);
			//if(dui[1].v<=n)cnt++;
			//ans+=dui[1].c;
			ans+=dui[1].w;
			cout<<ans<<' ';
		}
		remove(1);
		//cout<<cnt<<' '<<size<<endl;
		bool flag=1;
		//cout<<father[1]<<' ';
		for(int i=2;i<=n;i++){
			//cout<<father[i]<<' ';
			if(father[i]!=father[i-1]){
				flag=0;
				break;
			}
		}
		//cout<<endl;
		if(flag==1)break;
	}
	cout<<ans;
	return 0;
}

