#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N][4],st[N];
int t,c[4],n,sum,ma;
void dfs(int u){
	if(u>n){
		sum=max(sum,ma);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i]<n/2 or h[u][i]==0){
			ma+=h[u][i];
			c[i]++;
			dfs(u+1);
			c[i]--;
			ma-=h[u][i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		c[1]=0;c[2]=0;c[3]=0;
		sum=0;ma=0;
		memset(h,0,sizeof h);
		for(int i=1;i<=n;i++){
			cin>>h[i][1]>>h[i][2]>>h[i][3];
		}
		dfs(1);
		cout<<sum<<endl;
	}
	return 0;
}
