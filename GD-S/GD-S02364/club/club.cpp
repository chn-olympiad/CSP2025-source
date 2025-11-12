#include<bits/stdc++.h>
using namespace std;
int n,mx=-1,f[100005];
struct node{
	int a,b,c,x;
}a[100005];
void dfs(int x,int y,int z,int s,int i){
	if(x>n/2||y>n/2||z>n/2)
		return;
	
	if(x+y+z==n){
		mx=max(mx,s);
		return;
	}
	dfs(x+1,y,z,s+a[i].a,i+1);
	dfs(x,y+1,z,s+a[i].b,i+1);
	dfs(x,y,z+1,s+a[i].c,i+1); 
}
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		mx=0;
		cin>>n;
		bool f=0,ff=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0)
				f=1;
		}
		sort(a+1,a+n+1,cmp);
		if(f==0){
			for(int i=1;i<=n/2;i++)
				mx+=a[i].a;
			cout<<mx<<'\n';
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<mx<<'\n';
	}
}
