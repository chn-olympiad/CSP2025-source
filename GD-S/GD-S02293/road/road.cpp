#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int mapp[N][N],mazz[N][N],maq[N][N],dp[N][N];
int n,m,k,a,b,c,cnt=0,q;
bool teshu=true;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(dp,INT_MAX,sizeof(dp));
	memset(mapp,0,sizeof(mapp));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(c!=0) teshu=false;
		mapp[a][b]=mapp[b][a]=c;
		mazz[a][b]=mazz[b][a]=c;
	}
	if(teshu){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>q;
			if(j!=2) mapp[i][j]=min(mapp[i][j],q);
			mapp[j][i]=mapp[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mazz[i][j]!=min(mazz[i][j],mazz[i][k]+mazz[k][j])){
					mazz[i][j]=min(mazz[i][j],mazz[i][k]+mazz[k][j]);
					maq[i][j]=k;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt+=mazz[i][j];
		}
	}
	cnt/=2;
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
