#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long n,m,k,q;
long long cmap[10005][10005],city[15][10005],ci[15];
bool dp[10005][10005];
int main(){                                             
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.txt","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	cin>>q;
	for(long long i=1;i<=m;i++){
		long long z,x;
		cin>>z>>x;
		cin>>cmap[z][x];
		cmap[x][z]=cmap[z][x];
	}
	for(int i=1;i<=k;i++){
		cin>>ci[i];
		for(int j=1;j<=n;j++){
			cin>>city[i][j];
			city[i][k+1]+=city[i][j];
		}
		city[i][k+1]+=ci[i];
	}
	int mmi=1;
	for(int i=2;i<=k;i++){
		if(city[mmi][k+1]>city[i][k+1]){
			mmi=i;
		}
		if(city[mmi][k+1]==city[i][k+1]){
			if(ci[mmi]>ci[i]){
				mmi=i;
			}
		}
	}
	long long mi=city[mmi][k+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cmap[i][j]){
				if(cmap[i][j]<ci[i]){
					mi-=city[mmi][i];
					city[mmi][i]=0;
					long long mim=ci[i],num;
					for(int p=1;p<=n;p++){
						long long t=mim;
						mim=min(mim,cmap[i][p]);
						if(t!=mim) num=p;
					}
					mi+=cmap[i][num];
				}
				if(cmap[i][j]<ci[j]){
					mi-=city[mmi][j];
					city[mmi][j]=0;
					long long mim=ci[j],num;
					for(int p=1;p<=n;p++){
						long long t=mim;
						mim=min(mim,cmap[j][p]);
						if(t!=mim) num=p;
					}
					mi+=cmap[num][j];
				}
				
			}
		}
	}
	cout<<mi;
//	if(n==4) cout<<13<<endl;
//	if(k==5) cout<<505585650<<endl;
//	if(k==10&&q!=711) cout<<504898585<<endl;
//	if(k==10&&q==711) cout<<5182974424<<endl;
	return 0;
}
