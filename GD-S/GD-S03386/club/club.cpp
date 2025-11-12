#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int a[maxn][5],n,d[39][39][39][39];
int dfs(int x,int y,int b,int c){
	if(x==n+1)return 0;
	int cnt=0;
	if(y<n/2)cnt=max(cnt,dfs(x+1,y+1,b,c)+a[x][1]);
	if(b<n/2)cnt=max(cnt,dfs(x+1,y,b+1,c)+a[x][2]);
	if(c<n/2)cnt=max(cnt,dfs(x+1,y,b,c+1)+a[x][3]);
	return cnt;
}
int b[maxn];
pair<int,int>c[maxn];
void solve(){
	cin>>n;
	bool f1=1,f2=1;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];	
		b[i]=a[i][1];
		c[i].first=a[i][1]-a[i][2];
		c[i].second=a[i][1];
		ma+=max(max(a[i][1],a[i][2]),a[i][3]);
		if(a[i][2]!=0)f1=0;
		if(a[i][3]!=0)f1=f2=0;
	}
	if(n<=10){
		cout<<dfs(1,0,0,0)<<endl;
	}else if(f1){
		sort(b+1,b+1+n);
		int cn=0;
		for(int i=n/2+1;i<=n;i++)cn+=b[i];
		cout<<cn<<endl;
	}else if(f2){
		sort(c+1,c+1+n);
		int cn=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)cn+=c[i].second-c[i].first;
			else cn+=c[i].second;
		}
		cout<<cn<<endl;
	}else if(n<=30){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int g=0;g<=n/2;g++){
						d[i][j][k][g]=0;
						if(j!=0)d[i][j][k][g]=max(d[i][j][k][g],d[i-1][j-1][k][g]+a[i][1]);
						if(k!=0)d[i][j][k][g]=max(d[i][j][k][g],d[i-1][j][k-1][g]+a[i][2]);
						if(g!=0)d[i][j][k][g]=max(d[i][j][k][g],d[i-1][j][k][g-1]+a[i][3]);
						if(i==n)ans=max(ans,d[i][j][k][g]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}else{
		cout<<ma<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
