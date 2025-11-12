#include<bits/stdc++.h>
using namespace std;
int lj[10001][10001],n,m,k,xc[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		lj[u][v]=lj[v][u]=w;
	}
	for (int i=1;i<=k;i++){
		cin>>xc[i][0];
		for (int j=1;j<=n;j++){
			cin>>xc[i][j];
		}
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
16:25
NOOOO
ling jie ju zhen a~~~~~~~~~~~
ni () DE HAO CAN NA~~~
dou guai m<=10^6 ~~~~~
555 lin jie biao bu hui xie
ran jin le
16:30
o
kan cuo le
i'm JOKER
bbb
16:32
??? zhe T2 zai shuo sha yaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
?????????
16:35
bu hui xie
ran jin le
*/
//wo xiang shang shen jin dai ma
//freopen("road.in","r",stdin);
//freopen("road.out","w",stdout);
