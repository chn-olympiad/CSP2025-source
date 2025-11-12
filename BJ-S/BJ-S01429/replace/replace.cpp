#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int edge[1000001][3];
int c[100];
int a[50][10001];
int f[10001+100];
int choose[50];
int find(int x){
	if(f[x]!=x)return find(f[x]);
	else return x;
}
void chao(int x){
	memset(choose,0,sizeof choose);
	int y=1;
	while(x){
		if(x&1)choose[y]=1;
		y++;
		x/=2;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int sit=0;
	int finalans=1e9;
	while(sit<pow(2,k)-1){
		int xccnt=0;
		for(int i=1;i<=n+k;i++)f[i]=i;
		priority_queue<pair<int,pair<int,int> > > q;
		chao(sit);
		for(int i=1;i<=m;i++){
			q.push(make_pair(-edge[i][2],make_pair(edge[i][0],edge[i][1]) ) );
		}
		int ans=0;
		for(int i=1;i<=k;i++){
			if(!choose[i])continue;
			xccnt++;
			ans-=c[i];
			for(int j=1;j<=n;j++){
				q.push(make_pair(-a[i][j],make_pair(i+n,j) ) );
			}
		}
		int use=0;
		while(use<n+xccnt-1){
			pair<int,pair<int,int> > p=q.top();
			q.pop();
			int x=p.second.first;
			int y=p.second.second;
			int X=find(x);
			int Y=find(y);
			if(X==Y){
				continue;
			}
			f[X]=Y;
			ans+=p.first;
			use++;
		}
		ans=-ans;
		finalans=min(finalans,ans);
		sit++;
		//cout<<endl<<endl<<endl;
	}
	cout<<finalans;
	return 0;
}
