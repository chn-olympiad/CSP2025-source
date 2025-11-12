#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, t, a[100500][4], dp[1005000][4], f[100500], ans=-1, p[3];
void dfs(int dep, int s, int c[3]){
	if(dep>n){
		ans=max(ans, s);
	}
	for(int i=0;i<=2;i++){
		if(c[i]<n/2)
		c[i]++, dfs(dep+1, s+a[dep][i+1],c), c[i]--;
	}
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(;t--;){
		bool flaga=1;
		ans=-1;
		int x=0, y=0, z=0;
		int minx=1e18, miny=1e18, minz=1e18;
		int maxx=-1, maxy=-1, maxz=-1;
		int w=0;
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		int sum=0;
		cin >>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >>a[i][j];
				
			}
			if(a[i][2]!=0||a[i][3]!=0)flaga=0;
			sum+=a[i][1];
		}
		if(flaga){
			cout <<sum;
			return 0;
		}
		if(n<20)
		dfs(1,0,p); 
		//cout << ans<<endl;
		
		for(int i=1;i<=n;i++){
			minx=min(minx, a[i][1]);
			miny=min(miny, a[i][2]);
			minz=min(minz, a[i][3]);
			maxx=max(maxx, a[i][1]);
			maxy=max(maxy, a[i][2]);
			maxz=max(maxz, a[i][3]);
			int zuida=max(a[i][1], max(a[i][2], a[i][3]));
			if(a[i][1]==zuida){
				if(x>n/2){
					if(a[i][2]==zuida){
						w+=zuida;
						y++;
						continue;
					}
					if(a[i][3]==zuida){
						w+=zuida;
						z++;
						continue;
					}
					else{
						w+=zuida-minx;
						continue;
					}
				}else{
					w+=zuida;
					x++;
				}
				continue;
			}
			if(a[i][2]==zuida){
				if(y>n/2){
					if(a[i][1]==zuida){
						w+=zuida;
						x++;
						continue;
					}
					else if(a[i][3]==zuida){
						w+=zuida;
						z++;
						continue;
					}
					else{
						w+=zuida-miny;
						continue;
					}
				}
				else{
					w+=zuida;
					y++;
				}
				continue;
			}
			if(a[i][3]==zuida){
				if(z>n/2){
					if(a[i][1]==zuida){
						w+=zuida;
						x++;
						continue;
					}
					if(a[i][2]==zuida){
						w+=zuida;
						y++;
						continue;
					}
					else{
						w+=zuida-minz;
						continue;
					}
				}
				else{
					w+=zuida;
					z++;
				}
				continue;
			}
		}
		if(n>=20){
			cout << w<<endl;
			continue;
		}
		if(w==ans){
			cout << ans<<endl;
			continue;
		}if(w!=ans){
			cout << ans<<endl;
			continue;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=n/2;j>=1;j--){
//				for(int k=1;k<=3;k++){
//					dp[j][k]=max(dp[j][k],dp[n/2-j][k]+max(a[i][1],max(a[i][2], a[i][3])));
//					dp[j][k]=max(max(dp[j][1], max(dp[j][2], dp[j][3])), max(dp[j-1][1], max(dp[j-1][2], dp[j-1][3]))+a[i][k]);	
//				}
//			}
//		}
//		cout <<max(dp[n/2][1], max(dp[n/2][2], dp[n/2][3]))<<endl;
	}
	return 0;
}
