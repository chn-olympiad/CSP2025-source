#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 100010;
int s[MAXN][4];
bool vis[MAXN];
int a = 0,b = 0,c = 0;
int ans = 0; 
bool flag(int num){
	if(num == 1)	return a<(n/2);
	if(num == 2)	return b<(n/2);
	return c<(n/2);
}
void dfs(int chance){
	if(chance == n)	return;
	int maxn = -1;
	int x,y;
	for(int i = 1;i <= n;i++)	for(int j = 1;j <= 3;j++)	
		if(s[i][j] > maxn && !vis[i] && flag(j)){
		maxn = s[i][j];
		x = i;
		y = j;
	}	//找到最大满意度
	ans+=s[x][y];
	vis[x] = 1;
	if(y == 1)	a++;
	else if(y == 2)	b++;
	else c++;	//各公司人数 
	dfs(chance + 1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		a = 0;	b = 0;	c = 0;	ans = 0;
		cin>>n;
		for(int i = 1;i <= n;i++)	for(int j = 1;j <= 3;j++)	cin>>s[i][j];
		dfs(0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
