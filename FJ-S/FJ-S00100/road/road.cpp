#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
struct node{
	int u,v,w;
}r[N];
int n,m,k,ans,mina=1e8+10;
int c[20][10010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
			ans+=c[i][j];
		}
		mina=min(mina,ans);
		ans=0;
	}
	cout<<mina<<endl;
	return 0;	
} 
