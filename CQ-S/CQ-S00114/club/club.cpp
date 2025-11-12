//luogu _liu**lin_ tuiyizhizhan
//ganxie ccf geilewoyigerenqingzijidejihui
//wogaiqunali,wowenwoziji
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],f[205][105][105][105],ans;
priority_queue<int> q;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(j+k>i)continue;
						for(int l=0;l<=n/2;l++){
							if(l+k+j>i)break;
							f[i][j][k][l]=0;
							if(j>0)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j-1][k][l]+a[i][1]);
							if(k>0)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k-1][l]+a[i][2]);
							if(l>0)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l-1]+a[i][3]);
							ans=max(ans,f[i][j][k][l]);
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++)q.push(a[i][1]);
			for(int i=1;i<=n/2;i++){
				ans+=q.top();q.pop();
			}
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}
//60fen baoli
