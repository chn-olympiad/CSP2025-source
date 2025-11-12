#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int a[N][3],buk[3];
int n,rk[3],now;
vector<int>G[N];
priority_queue<int,vector<int>,greater<int> >q[3];
bool cmp(int x,int y){return a[now][x]>a[now][y];}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int Tn;scanf("%d",&Tn);
	while(Tn--){
		scanf("%d",&n);int ans=0;
		buk[0]=buk[1]=buk[2]=0;
		for(now=1;now<=n;now++){
			for(int j=0;j<3;j++){
				scanf("%d",&a[now][j]);
				rk[j]=j;
			}
			sort(rk,rk+3,cmp);
			buk[rk[0]]++;ans+=a[now][rk[0]];
			q[rk[0]].push(a[now][rk[0]]-a[now][rk[1]]);
		}
		for(int j=0;j<3;j++){
			if(buk[j]<=n/2){
				while(!q[j].empty())q[j].pop();
				continue;
			}
			while(!q[j].empty()&&buk[j]>n/2)
				buk[j]--,ans-=q[j].top(),q[j].pop();
			while(!q[j].empty())q[j].pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
