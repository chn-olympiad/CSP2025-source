#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[20000],s[10000][20000],ans,M;
vector<int>a[10005];
struct node{
	int x,y,z;
	};
int opratier +(int a,int b){
	return a-b;
	};
priority_queue<node> q;
vector<node> a[20000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		node c;
		c.x=x,c.y=z;
		a[y].push_back(c);
	}
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				if(f[j]!=0x3f3f3f){
					f[i]=min(f[i],f[j]+a[i][j]);
					}
			for(int i=1;i<=n;i++){
					M=max(M,f[i]);
				}
				cout<<M;
			}
}
return 0;
}

