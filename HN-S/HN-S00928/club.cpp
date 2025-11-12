#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int t,n,a[N][3],tong[N],st[N][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--){
		memset(tong,0,sizeof(tong));
		memset(st,0,sizeof(st));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				ans+=a[i][1];
				tong[1]++;
				st[i][1]=1;
			}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				ans+=a[i][2];
				tong[2]++;
				st[i][2]=1;
			}else{
				ans+=a[i][3];
				tong[3]++;
				st[i][3]=1;
			}
		}
		int mn=INT_MAX;
		for(int i=1;i<=3;i++){
			while(tong[i]>n/2){
				for(int j=1;j<=n;j++){
					if(st[j][i]==1){
						mn=min(a[j][i],mn);
						tong[i]--;
					}
				}
				int x;
				for(int j=1;j<=n;j++){
					if(a[j][i]==mn){
						x=j;
						break;
					}
				}
				ans-=mn;
				st[x][i]=0;
				if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]&&a[x][2]>=a[x][3]){
					tong[2]++;
					ans+=a[x][2];
					st[x][2]=1;
				}else if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]&&a[x][3]>=a[x][2]){
					tong[3]++;
					ans+=a[x][3];
					st[x][3]=1;
				}else if(a[x][3]>a[x][1]&&a[x][3]>a[x][2]&&a[x][1]>=a[x][2]){
					tong[1]++;
					ans+=a[x][1];
					st[x][1]=1;
				}else if(a[x][3]>a[x][1]&&a[x][3]>a[x][2]&&a[x][2]>=a[x][1]){
					tong[2]++;
					ans+=a[x][2];
					st[x][2]=1;
				}else if(a[x][2]>a[x][1]&&a[x][2]>a[x][3]&&a[x][1]>=a[x][3]){
					tong[1]++;
					ans+=a[x][1];
					st[x][1]=1;
				}else if(a[x][2]>a[x][1]&&a[x][2]>a[x][3]&&a[x][3]>=a[x][1]){
					tong[3]++;
					ans+=a[x][3];
					st[x][3]=1;
				}
			}
		}
		for(int i=1;i<=3;i++){
			while(tong[i]>n/2){
				for(int j=1;j<=n;j++){
					if(st[j][i]==1){
						mn=min(a[j][i],mn);
						tong[i]--;
					}
				}
				int x;
				for(int j=1;j<=n;j++){
					if(a[j][i]==mn){
						x=j;
						break;
					}
				}
				ans-=mn;
				st[x][i]=0;
				if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]&&a[x][2]>=a[x][3]){
					tong[3]++;
					ans+=a[x][3];
					st[x][3]=1;
				}else if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]&&a[x][3]>=a[x][2]){
					tong[2]++;
					ans+=a[x][2];
					st[x][2]=1;
				}else if(a[x][3]>a[x][1]&&a[x][3]>a[x][2]&&a[x][1]>=a[x][2]){
					tong[2]++;
					ans+=a[x][2];
					st[x][2]=1;
				}else if(a[x][3]>a[x][1]&&a[x][3]>a[x][2]&&a[x][2]>=a[x][1]){
					tong[1]++;
					ans+=a[x][1];
					st[x][1]=1;
				}else if(a[x][2]>a[x][1]&&a[x][2]>a[x][3]&&a[x][1]>=a[x][3]){
					tong[3]++;
					ans+=a[x][3];
					st[x][3]=1;
				}else if(a[x][2]>a[x][1]&&a[x][2]>a[x][3]&&a[x][3]>=a[x][1]){
					tong[1]++;
					ans+=a[x][1];
					st[x][1]=1;
				}
			}
		}
		ans=max(ans,a[1][2]+a[2][1]);
		cout<<ans<<'\n';
	}
	return 0;
}
