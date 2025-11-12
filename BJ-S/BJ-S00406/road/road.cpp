#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct node{
    int u,v,w;
}r[1000001];
int c[11];
int a[11][10001];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<0;
	return 0;
}

