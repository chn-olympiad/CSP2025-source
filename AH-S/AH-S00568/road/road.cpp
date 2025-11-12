#include "bits/stdc++.h"
using namespace std;
int a[10001][10001],w[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	memset(a,0x3f3f3f,sizeof(a));
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		int xp,s=0;
		cin>>xp;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			if(xp+w<a[i][j]){
				s++;
				a[i][j]=0x3f3f3f;
				a[j][i]=0x3f3f3f;
				ans+=xp+w;
			}
		}
		if(s==0) continue;
		ans-=xp*(s-1);
		w[i]=1;
		n--;
	}
	int f[100010],flag=1;
	for(int i=1;i<=n&&flag;i++){
		if(w[i]==0){
			f[0]=i;
			flag=0;
			break;
		}
	}
	//cout<<ans<<" "<<w[1]<<endl;
	if(flag==1){
		cout<<ans<<endl;
		return 0;
	}
	//for(int i=1;i<=n;i++){
		//for(int j=1;j<=n;j++)
			//cout<<a[i][j]<<" ";
		//cout<<endl;
	//}
	int cnt=1;
	for(int i=0;i<cnt;i++){
		int minn=INT_MAX,node=0;
		for(int j=1;j<=n;j++){
			if(j!=f[i]&&w[j]==0){
				if(minn>a[i][j]) minn=a[i][j],node=j;
			}
		}
		if(node==0) continue;
		ans+=minn;
		w[node]=1;
		cnt++;
		if(cnt==n+1){
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
