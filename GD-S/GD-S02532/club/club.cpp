#include<bits/stdc++.h>
using namespace std;
int a[100007][4],t,n,anss,p[4],b[20007];
void dfs(int k,int m,int ans){
	if(k==n){
		anss = max(anss,ans);
		return;
	}else{
		for(int i = 1;i<=3;i++){
			if(p[i]>=n/2){
				continue;
			}p[i]++;
			dfs(k+1,i,a[k+1][i]+ans);
			p[i]--;
		}
	}return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	cin >> t;
	while(t--){
		anss = 0;
		cin >> n;
		bool f = 1;
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				f = 0;
			}
		}if(f){
			int ans = 0,cnt = 0;
			memset(b,sizeof(b),0);
			for(int i = 1;i<=n;i++){
				b[a[i][1]]++;
			}for(int i = 20001;i>=0;i--){
				if(b[i]){
					if(cnt+b[i]<=n/2){
						ans+=i*b[i]; 
					}else{
						while(cnt<n/2){
							ans+=i;
							cnt++;
						}
					}
				}
			}cout << ans << endl;
			continue;
		}for(int i = 1;i<=3;i++){
			p[i]++;
			dfs(1,i,a[1][i]);
			p[i]--;
		}cout << anss << endl;
	}
	return 0;
} 
