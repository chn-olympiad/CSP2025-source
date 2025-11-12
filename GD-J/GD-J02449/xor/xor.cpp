#include<bits/stdc++.h>
using namespace std;
int xo[8005][8005];
int n,m,a[200005],xj,x,y,sum,ans;
bool vis[200005];
string s;
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)  m=1;
	}
	if(m<=1){
		cout<<n/2;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				xo[i][j]=xo[i][j-1]^a[j];
			}
		}
		for(int i=1;i<=n;i++){
			xo[i][i]=a[i];
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<xo[i][j]<<endl;
//			}
//		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			ans=0;
			for(int j=1;j<=n;j++){
//				cout<<j;
				for(int k=j;k<=n;k++){
//					cout<<1;
					if(xo[j][k]==x&&vis[j]!=1&&vis[k]!=1){
						for(int z=j;z<=k;z++)  vis[z]=1;
						ans++;
//						cout<<j<<' '<<k<<'\n';
						//j=k+1;
						break;
					}
//					cout<<endl;
				}
			}
//			cout<<'\n';
			sum=max(sum,ans);
		}
	}
	cout<<sum;
	return 0;
} 
