#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int l=0;
struct node{
	int o,p,w;
};
node G[N*3];
int r[N],fu[N],z[N],st[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
void connect(int a,int b){
	if(!st[a]&&(!st[b])){
		fu[a]=b;
		fu[b]=a;
		z[a]=2;
		z[b]=2;
		st[a]=1;
		st[b]=1;
		l+=2;
		r[a]=b;
	
	}else if(st[a]&&(!st[b])){
		fu[b]=fu[a];
		l++;
		z[fu[a]]++;
		st[b]=1;
		r[b]=a;
	}else{
		if(z[fu[a]]>=z[fu[b]]){
			z[fu[a]]+=z[fu[b]];
			l+=z[fu[b]];
			int y=fu[b];
			r[fu[b]]=a;
			fu[fu[b]]=fu[a];
			int x=r[b];
			fu[b]=fu[a];
			
			while(x!=y){
				fu[x]=fu[a];
				x=r[x];
			}
		}else{
			z[fu[b]]+=z[fu[a]];
			l+=z[fu[a]];
			int y=fu[a];
			r[fu[a]]=b;
			fu[fu[a]]=fu[b];
			int x=r[a];
			fu[a]=fu[b];
			
			while(x!=y){
				fu[x]=fu[b];
				x=r[x];
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m,k;
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>G[i].o>>G[i].p>>G[i].w;
	}
	if(n<=10000&&m<=1000000&&k==0){
		sort(G+1,G+m+1,cmp);
		int j=0;	
		for(int i=1;i<=(m-1);i++){
			if(st[G[i+j].o]&&st[G[i+j].o]){
				j++;
				continue;
			}
			st[G[i+1].o]=1;
			st[G[i+1].o]=1;
			ans+=G[i+j].w;
		}
		cout<<ans<<endl;
	}else{
		cout<<0<<endl;
	}
	
	return 0;
}