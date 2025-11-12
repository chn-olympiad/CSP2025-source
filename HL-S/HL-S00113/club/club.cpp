#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
long long f[4][50001];
long long w[100001][4];
void dfs(int k1,int k2,int k3,int l,long long num){
	if(l>=n+1){
		ans=max(ans,num);return;
	}
	if(k1>0)dfs(k1-1,k2,k3,l+1,num+w[l][1]);
	if(k2>0)dfs(k1,k2-1,k3,l+1,num+w[l][2]);
	if(k3>0)dfs(k1,k2,k3-1,l+1,num+w[l][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(f,0,sizeof(f));
		bool flag=0;
		for(int i=1;i<=n;i++){
//			cin>>p[i].a>>p[i].b>>p[i].c;
			cin>>w[i][1]>>w[i][2]>>w[i][3];
			if(w[i][2]==0&&w[i][3]==0){ans+=w[i][1];
				if(!flag&&i!=n)flag=1;
				continue;
			}
			flag=0;
		}
		if(flag){cout<<ans<<endl;return 0;
		}
//		for(int j=n/2;j>=0;j--){
//			for(int k=1;k<=3;k++){
//				for(int i=1;i<=n;i++){
//					f[k][j]=max(f[k][j],f[k][j+1]+w[i][k]);
//				}
//			}
//		}
		dfs(n/2,n/2,n/2,1,0);
		cout<<ans<<endl;
	}
	return 0;
}
