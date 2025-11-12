#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,w,ans[20000080],l,anss,c[28],a[18][10008],b[2008][2008];
struct tt{
	long long yy,w;
};
vector<tt>f[20008],cz[20008];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int pd1=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		f[x].push_back({y,w});
		if(k==0){
			ans[++l]=w;
		}
	}
	if(k==0){
		sort(ans+1,ans+1+l);
		for(int i=1;i<=n-1;i++){
			anss+=ans[i];
		}
		return cout<<anss,0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i][j]=1e18;
		}
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		pd1=pd1+(c[i]==0);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			cz[i].push_back({j,a[i][j]});
			pd1=pd1+(c[i]==0);
		}
		for(int j=1;j<=n;j++){
			for(int o=j+1;o<=n;o++){
				b[j][o] =min(b[j][o],a[i][j]+a[i][o]+c[i]);	
			}	
		}
	}
	if(pd1==k*(n+1)){
		return cout<<0,0;
	}

	else{
		for(int i=1;i<=m;i++){
			for(int j=0;j<f[i].size();j++){
				if(b[i][f[i][j].yy ]<=f[i][j].w ) continue;
				ans[++l]=f[i][j].w;
				//cout<<f[i][j].w<<" ";
			}
			for(int j=i+1;j<=n;j++) {
				ans[++l]=b[i][j];
			//	cout<<b[i][j]<<" ";
			}
			//cout<<"\n";
		}
		sort(ans+1,ans+1+l);
		/*cout<<l<<"\n";
		for(int i=1;i<=l;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";*/
		for(int i=1;i<=n-1;i++) anss+=ans[i];
		cout<<anss; 
	} 
}
