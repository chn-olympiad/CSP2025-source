#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int T,n;
int a[N][5];
int b[5];
bool vis[N];
int c[N];
//struct node{
//	long long id,x;
//	
//	bool operator < (const  node y) const{
//		return x<y.x;
//	}
//};
//long long ans=0;
//priority_queue<node> q[5];
long long ans=0;
void dfs(int x,long long s){
	if(x==n+1){
		ans=max(ans,s);
		return;
	}
	if(b[1]<n/2){
		b[1]++;
		dfs(x+1,s+a[x][1]);
		b[1]--;
	}
	if(b[2]<n/2){
		b[2]++;
		dfs(x+1,s+a[x][2]);
		b[2]--;
	}
	if(b[3]<n/2){
		b[3]++;
		dfs(x+1,s+a[x][3]);
		b[3]--;
	}
	
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>T;
	
	
	while(T--){
		cin>>n;
		ans=0;
		b[1]=b[2]=b[3]=0;
		bool f=0,t=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			c[i]=a[i][1];
			if(a[i][2]!=0) f=1;
			if(a[i][3]!=0) t=1;
		}
		if(!f && !t){
			sort(c+1,c+n+1);
			for(int i=n;i>n/2;i--) ans+=c[i];
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
