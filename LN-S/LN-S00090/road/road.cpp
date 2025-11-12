#include<bits/stdc++.h>
using namespace std;

struct road{int u,v,w;}r[1000005];
struct node{int from,to;}nod[1000005];

signed main(){
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);

    int n,m,k;cin>>n>>m>>k;
    //if(k==0){
		int ans=0;
		for(int i=1;i<=m;i++){cin>>r[i].u>>r[i].v>>r[i].w;ans+=r[i].w;}
		//cout<<dfs(r[1],0)<<endl;
		cout<<ans<<endl;
	//}



    return 0;
}
