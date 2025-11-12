#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>mp[10005],vallage[10005];
int g[10005][10005],val[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(g,-1,sizeof(g));
	for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        mp[x].push_back(y);
        mp[y].push_back(x);
        g[x][y]=g[y][x]=w;
	}
	int sum=0;
	for(int i=1;i<=k;i++){
	    int w;
        cin>>w;
        sum+=w;
        val[i]=w;
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            vallage[i].push_back(x);
        }
	}
	if(sum==0){
        cout<<0;
        return 0;
	}
	int cnt=1919810;
	for(int i=1;i<=n;i++){
        int minn=114514,idx;
        int dis[100005]={};
        dis[i]=1919810;
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            if(g[i][j]==-1)dis[j]=1919810;
            dis[i]=g[i][j];
            if(dis[j]<maxn){
                idx=j;
                minn=dis[j];
            }
        }
        for(int j=1;j<=n;j++){
            if(g[idx][j]!=-1){
                if(dis[j]>dis[idx]+g[idx][j]){
                    dis[j]=dis[idx]+g[idx][j];
                }
            }
        }
        int ans=0;
        for(int j=1;j<=n;i++){
            if(i==j)continue;
            ans+=dis[j];
        }
        cnt=min(cnt,ans);
	}
	cout<<cnt;
	return 0;
}
