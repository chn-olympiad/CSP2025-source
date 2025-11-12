#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int T,ans;
int n,a[MAXN][5],hn,g[5];
priority_queue<int> p; 
void solve1(int x,int now){
	if(x==n+1){
		ans=max(ans,now);
		return;
	}
	for(int i=1;i<=3;i++){
		if(g[i]==hn) continue;
		g[i]++;
		solve1(x+1,now+a[x][i]);
		g[i]--;
	}
	return;
}
void solveA(){
	for(int i=1;i<=hn;i++){
		ans+=p.top();
     	p.pop();	
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&T);
    int x2,x3;
    while(T--){
    	g[1]=0;
		g[2]=0;
		g[3]=0;
		x2=0;
		x3=0;
    	scanf("%d",&n);
    	hn=n/2;
		ans=-1;
    	for(int i=1;i<=n;i++){
    		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
    		p.push(a[i][1]);
    		if(a[i][2]==0) x2++;
    		if(a[i][3]==0) x3++;
		} 
		if(n<=10) solve1(1,0);
		else if(x2==n&&x3==n) solveA();
    	printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
1 0 0
3 0 0
2 0 0
7 0 0
*/
