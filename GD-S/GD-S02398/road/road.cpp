#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MAXN=100000010;

struct road{
	LL x;
	LL y;
	LL mon;
};

LL n,m,k,tp[MAXN][MAXN][2],ans=0;
road t[MAXN][MAXN];

LL fb(LL u,LL v){
	if(u>n && v>n){
		return ans;
	}
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			if(tp[u][v][0]==1){
				t[u][v].x=u;
				t[u][v].y=v;
				t[u][v].mon=tp[u][v][1];
			}
		}
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			if(t[i][j].mon>min(t[i][j+1].mon,t[i+1][j+1].mon)){
				ans+=min(t[i][j+1].mon,t[i+1][i+1].mon);
				fb(i,j);
			}
		}
	}
}




int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	LL x,y,w;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		tp[x][y][0]=1;
		tp[x][y][1]=w;
	}
	fb(1,1);
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
