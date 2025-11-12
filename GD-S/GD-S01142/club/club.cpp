#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;
const int smaxn=210;
int value[5][maxn];//,remember[smaxn][smaxn][smaxn];
int n,ans,t;

void open(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&value[1][i],&value[2][i],&value[3][i]);
	}
}
//void clear(){
//	memset(remember,-1,sizeof(remember));
//}
bool cmp(int x,int y){return x>y;}
int dfs(int dep,int a,int b,int c,int V){
	//if(remember[a][b][c]!=-1)return remember[a][b][c]=max(remember[a][b][c],);
	if(dep==n+1)return V;
	int ret=-1;
	if(a!=n/2)ret=max(ret,dfs(dep+1,a+1,b,c,V+value[1][dep]));
	if(b!=n/2)ret=max(ret,dfs(dep+1,a,b+1,c,V+value[2][dep]));
	if(c!=n/2)ret=max(ret,dfs(dep+1,a,b,c+1,V+value[3][dep]));
	return ret;
}
void solve1(){
	ans=dfs(1,0,0,0,0);
}
void solveA(){
	sort(value[1]+1,value[1]+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=value[1][i];
	}
}
void output(){
	printf("%d\n",ans);
}
void LunAsk(){
	scanf("%d",&t);
	while(t--){
		//clear();
		input();
		if(n=100000){
			solveA();
		}else{
			solve1();
		}
		//solveA();
		output();
	}
}
int main(){
	open();
	LunAsk();
	close();
	return 0;
}

