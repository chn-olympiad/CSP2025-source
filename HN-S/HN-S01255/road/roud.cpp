#include<bits/stdc++.h>
using namespace std;
const int M=1e6+2;
const int N=1e4+2;
struct city{pair<int,int> apl[N];int len;}p[N];
struct vel{int pr,ta[N];}apv[11];
int n,m,k;
long long ans=9e18;
bool vl[20];
int vs=0;
bool v[N];
void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++){
		p[i].len = 0;
	}
	for(int i = 1;i <= m;i++){
		int pl1,pl2,pr;
		scanf("%d%d%d",&pl1,&pl2,&pr);
		p[pl1].apl[++p[pl2].len]={pl2,pr};
		p[pl2].apl[++p[pl1].len]={pl1,pr};
	}
	for(int i = 1;i <= k;i++){
		scanf("%d",&apv[i].pr);
		for(int j = 1;j <= n;j++){
			scanf("%d",&apv[i].ta[j]);
		}
	}
}
void work(int id,long long res,int js){
	if(id==0||id>n)return ;
	if(js==n){
		if(res<ans)ans=res;
		return ;
	}
	int len=p[id].len;
	for(int i = 1;i <= len;i++){
		int to=p[id].apl[i].first,pr=p[id].apl[i].second;
		if(v[to]!=1){
			v[to]=1;
			work(to,res+pr,js+1);
			v[to]=0;
		}
		if(vs=k)continue;
		for(int j = 1;j <= n;j++){
			if(v[j]==1||i==j)continue;
			v[j]=1;
			work(j,res,js+1);
			v[j]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	work(1,0,0);
	cout << ans;
	return 0;
}
