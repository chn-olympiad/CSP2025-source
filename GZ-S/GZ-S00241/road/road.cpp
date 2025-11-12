//GZ-S00241 安顺市第二高级中学 李舜杰 
#include<bits/stdc++.h>
#define N 1000005
typedef long long  LL;
using namespace std;
const int mod=998244353;
//Ren5Jie4Di4Ling5%
int n,m,k;
int u[N],v[N],w[N],a[15][10005];
LL ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie();cout.tie();
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}

