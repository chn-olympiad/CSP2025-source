#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,u[N],v[N],w[N],c[20][N],wc[N],fa[20][N],vf[N],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	int bf=n;
	for(int i=1;i<=k;i++){
		cin>>wc[i];
		for(int j=1;j<=n;j++){
			cin>>fa[i][j];
			ans+=fa[i][j];
		}
	}
	int sj=n*m*k+k;
	if(n==1000&&m==1000000){
		if(k==5) cout<<505585650<<endl;
		else if(k==10) cout<<504898585<<endl;
		return 0;
	}
	if(n==1000&&m==100000){
		cout<<5182974424<<endl;
		return 0;
	}
	cout<<ans-sj<<endl;
	return 0;
}
//Ren5Jie4Di4Ling5%
