#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,s[11111];
long long p[11111][11111],c[15][11111];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y>>p[x][y];
		s[x]++;s[y]++;
		ans+=p[x][y];
	}for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]==0) continue;
			for(int w=1;w<=k;w++){
				if(c[w][1]+c[w][i+1]+c[w][j+1]<p[i][j]) p[i][j]=c[w][1]+c[w][i+1]+c[w][j+1];
			} 
		}
	}
	
	for(int t;m>n-1;){//È¥µô¹óÂ· 
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(p[i][j]) t++;
				if(p[j][i]) t++;
			}
		}
		if(t==1) break;
		for(int i=1,maxx=-1,x,y;i<=m;i++){
			if(s[i]!=1){
				for(int j=1;j<=m;j++){
					if(s[j]==1) continue;
					if(maxx<p[i][j]){
						maxx=p[i][j];
						x=i;y=j;
					}
					if(maxx<p[j][i]){
						maxx=p[j][i];
						x=j;y=i;
					}
				}
			}
			if(i==m){
				ans-=maxx;
				p[x][y]=0;
				s[x]--;s[y]--;
				m--;
			}
		}
	}
	cout<<ans;
	return 0;
}
