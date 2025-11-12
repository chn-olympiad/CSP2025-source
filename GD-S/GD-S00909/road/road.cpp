#include<iostream>
#include<algorithm>
using namespace std;
const int ma=1e6+5;
struct Node{
	int u,v,c;
}a[ma];
bool cmp(Node a,Node b){
	return a.c<b.c;
}
bool st[1005];
int cc[15][ma];
int main(){
 	freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].c;
	}
	bool zero=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>cc[i][j];
			if(cc[i][j]!=0)zero=0;
		} 
	}
	if(zero&&k!=0){
		cout<<0;
		return 0;
	} 
	sort(a+1,a+1+n,cmp);
	int ans=0;
	bool flag=1;
	while(flag){
		flag=0;
		for(int i=1;i<=m;i++){
			if(st[a[i].u]&&st[a[i].v]||!st[a[i].u]&&!st[a[i].v]&&i!=1)continue;
			ans+=a[i].c;
			st[a[i].u]=1;
			st[a[i].v]=1;
			flag=1;
		}
	}
	cout<<ans;
	return 0;
}

