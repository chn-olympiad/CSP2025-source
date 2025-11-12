#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k;
ll v[10005][10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(v[a][b]==0)v[a][b]=c;
		else v[a][b]=min(v[a][b],c);
		if(v[b][a]==0)v[b][a]=c;
		else v[b][a]=min(v[b][a],c);
	}
	for(int i=1;i<=k;i++){
		ll c,a[n+5];
		cin>>c;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll vc=c+a[i]+a[j];
				if(v[i][j]==0)v[i][j]=vc;
				else v[i][j]=min(v[i][j],vc);
				if(v[j][i]==0)v[j][i]=vc;
				else v[j][i]=min(v[j][i],vc);
			}
		}
	}

	bool d[n+5][n+5]={0};
	ll ans=0,minn;
	for(int i=1;i<=n;i++){

		minn=100000005;
		ll num;
		bool qp=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(d[i][j] or d[j][i])continue;
			qp=1;
			if(v[i][j]<minn){num=j;
			minn=v[i][j];
			//cout<<i<<' '<<j<<endl;
			}
			
			
		}
//	cout<<minn<<endl;
		d[i][num]=1;
		for(int j=1;j<=n;j++){
			if(d[i][j] or d[num][j]){
				d[i][j]=1;d[j][i]=1;
				d[num][j]=1;d[j][num]=1;
				
			}
		}
		if(qp)ans+=minn;
	}
	cout<<ans;
	return 0;
} 
