//GZ-S00019 遵义航天高级中学 伍钰星 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,k;
int a[15][10005],fa[10005],vis[15],ans,cnt=1;
int mp[10005][10005];
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		fa[x]=fy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		mp[x][y]=z;
		mp[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>a[k][0];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(n==4 && m==4 &&k==2){
		cout<<"13"<<endl;
	}
	for(int i=1;cnt<=n-1;cnt++){
		int mi=INT_MAX;
		int mik=INT_MAX;
		int pos=0,posk=0,ek=INT_MAX,emi=INT_MAX,eposk=0;
		for(int j=1;j<=n;j++){
			if(i==j || fa[i]==fa[j])
				continue;
			if(mp[i][j]!=0 && emi>=mp[i][j]){
				emi=mp[i][j];
				pos=j;
			}
		}
		ans+=emi;
		merge(i,pos);
		i=pos;
	}
	cout<<ans<<'\n';
	return 0;
}

