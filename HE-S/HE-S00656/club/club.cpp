#include<bits/stdc++.h>
using namespace std;
int t_len[4];
int m[4][100001];
int k[100005];
int n;
int maxn=-1,tot;
bool cmp(int x,int y){
	if(x>y)return 1;
	return 0;
}
void dfs(int num){
	if(num==n+1){
		maxn=max(maxn,tot);
		return;
	}
	for(int i=1;i<=3;i++){
		if(t_len[i]<n/2){
			t_len[i]++;
			tot+=m[i][num];
			dfs(num+1);
			t_len[i]--;
			tot-=m[i][num];
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n>30){
		for(int i=1;i<=n;i++)
		scanf("%d%d%d",&m[1][i],&k[i],&m[3][i]);
		sort(k+1,k+n+1,cmp);
		maxn=0;
		for(int i=1;i<=n/2;i++)maxn+=k[i];
		cout<<maxn<<endl;
		}
		for(int i=1;i<=n;i++) scanf("%d%d%d",&m[1][i],&m[2][i],&m[3][i]);
		dfs(1);
		cout<<maxn<<endl;
		maxn=-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
