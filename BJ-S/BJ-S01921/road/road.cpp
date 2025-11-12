#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct e{
	int a,b,w;
};
e city[M];
bool vis[N];

bool cmp(e x,e y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int vi,ui,wi;
        cin>>vi>>ui>>wi;
        city[i].a=vi;city[i].b=wi;city[i].w=wi;
    }
    
    sort(city+1,city+m+1,cmp);
    
    int ans=0,num=n-1;
    for(int i=1;i<=m;i++){
		if(vis[city[i].a]==0 || vis[city[i].b]==0){
			ans+=city[i].w;
			vis[city[i].a]=1;vis[city[i].b]=1;
			num--;
        }
        if(num==0) break;
    }
    cout<<ans;
    return 0;
}