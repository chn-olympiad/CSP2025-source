#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[10],a[10][10010],ww[1001000];
struct node{
    int v,w;
};
bool fa;
vector<node>e[10010];
bool fa;
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        ww[i]=w;
	}
	if(k>=1)fa=1;
	for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0)fa=0;
        }
        if(c[i]!=0)fa=0;
	}
	if(fa){
        cout<<0;
        return 0;
	}
	if(k==0){
        sort(ww+1,ww+m+1);
        long long sum=0;
        for(int i=1;i<n;i++){
            sum+=ww[i];
        }
        cout<<sum;
	}else{
	}
	return 0;
}
