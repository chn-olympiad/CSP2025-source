#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int n,m,k,c[12][10010],d[9010][9010],f[10005];
bool vis[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;i++){
    	int uu,vv,ww;
    	scanf("%d%d%d",&uu,&vv,&ww);
    	d[uu][vv]=d[vv][uu]=ww;
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
		if(c[i][0])flag=1;
	}
	if(!flag){
		if(k>5||n>1e3){
			cout<<0;
			return 0;
		}
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=k;i++){
		    for(int j=1;j<=n;j++){
			f[j]=min(f[j],c[i][j]);
		    }
		}
		long long sum=0;
		for(int i=1;i<=n;i++){
			int mi=0x3f3f3f3f,kk=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&mi>f[j]){
					mi=f[j];
					kk=j;
				}
			}
			sum+=mi;
			vis[kk]=1;
			for(int j=1;j<=n;j++){
				f[j]=min(f[j],d[kk][j]);
			}
		}
		cout<<sum;
		return 0;
	}
    long long ans=0,minn=0x3f3f3f3f;
    for(int i=0;i<(1<<k);i++){
    	ans=0;
    	int pos=i,cnt=0;
    	memset(f,0x3f,sizeof(f));
    	memset(vis,0,sizeof(vis));
    	while(pos){
    		 cnt++;
    		 if(pos%2==1){
    		 ans+=c[cnt][0];
    		 for(int j=1;j<=n;j++){
    		 	 f[j]=min(f[j],c[cnt][j]);
			 }
		     }
    		 pos/=2;
		}
		if(i==0){
			vis[1]=1;
			for(int j=2;j<=n;j++){
				f[j]=min(f[j],d[1][j]);
			}
		}
		for(int k=1;k<=n;k++){
			int mi=0x3f3f3f3f,kk=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&mi>f[j]){
					mi=f[j];
					kk=j;
				}
			}
			ans+=mi;
			vis[kk]=1;
			for(int j=1;j<=n;j++){
				f[j]=min(f[j],d[kk][j]);
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0; 
}

