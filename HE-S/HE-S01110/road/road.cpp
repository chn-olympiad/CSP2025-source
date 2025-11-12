#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long ans;
bool isconnected[10005];
long long g[10005][10005],G[10005][10005];
long fr[10005],to[10005],cost[10005];
long long ti=0;
long long town[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout)
	cin>>n>>m>>k;
	for(int i=0;i<n+10;i++) isconnected[i]=false;
	for(int i=0;i<m;i++){
		int ta,tb,tc;
		cin>>ta>>tb>>tc;
		g[ta][ta]=tc;
		g[tb][ta]=tc;
	}
	isconnected[1]=true;
//	cout<<"_________________________________"<<endl;
	for(int i=2;i<=n;i++){
		//cout<<"_________________________________"<<endl;
		long long minf=1000000,mint=1000000,minn=1000000;
		//cout<<"_________________________________"<<endl;
		for(int f=1;f<=n;f++){
		//	cout<<"_________________________________"<<endl;
			for(int t=1;t<=n;t++){
			//	cout<<"_________________________________"<<endl;
				if(isconnected[f]&&!isconnected[t]&&g[f][t]!=0){
					if(g[f][t]<minn){
						minf=f;mint=t;
						minn=g[f][t];
					}
				}
			}
			//cout<<f<<" "<<t<<endl;
		}
		G[minf][mint]=minn;
		fr[ti]=minf;to[ti]=mint;cost[ti]=minn;
		ti++;
		ans+=minn;
	}//cout<<ans;
	long long minn=ans;
	for(int index=0;index<k;index++){
		ans=minn;
		int costt;
		cin>>costt;
		ans+=costt;
		for(int i=1;i<=n;i++) cin>>town[i];
		for(int i=0;i<ti;i++) if(G[fr[i]][to[i]]>town[fr[i]]+town[to[i]]) ans+=G[fr[i]][to[i]]-town[fr[i]]+town[to[i]];
		minn=min(minn,ans);
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
