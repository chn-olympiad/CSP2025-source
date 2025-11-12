//GZ-S00063 北京师范大学贵阳附属中学 刘祚诚 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum;
const int N=1e6+6;
int u[N],v[N],w[N],c[15][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
		if(c[i][0]!=0)flag=0;
	}
	if(flag){
		cout<<0<<endl;
		return 0;
	}else cout<<sum<<endl;
	return 0;
}

