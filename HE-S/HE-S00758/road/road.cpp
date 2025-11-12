#include<bits/stdc++.h>
using namespace std;

const int MN=2e6+10;
int n,m,k,cnt,tot;
long long ans;
struct Node{
	int x,y,k;
	
	bool operator<(const Node &other)const{
		return k<other.k;
	}
}s[MN];

int fa[MN];

int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}

void work1(){
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>s[cnt].x>>s[cnt].y>>s[cnt].k;	
	}
	
	tot=n;
	
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		tot++;
		for(int j=1;j<=n;j++){
			cnt++;
			s[cnt].x=tot,s[cnt].y=j;
			cin>>s[cnt].k;
		}
	}
	
	sort(s+1,s+cnt+1);
	
	for(int i=1;i<=tot;i++) fa[i]=i;
	
	for(int i=1;i<=cnt;i++){
		int x=s[i].x,y=s[i].y,k=s[i].k;
		if(find(x)==find(y)) continue;
		ans+=k;
		merge(x,y);
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	work1(); 
		
	return 0;
}
