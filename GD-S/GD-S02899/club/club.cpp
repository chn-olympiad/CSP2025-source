#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+5;
int n,a[N][3],id[3];
priority_queue<int>q[3];
void HitachiMako(){
	scanf("%d",&n);
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			scanf("%d",a[i]+j),id[j]=j;
		sort(id,id+3,[&](int x,int y){return a[i][x]>a[i][y];});
		q[id[0]].push(a[i][id[1]]-a[i][id[0]]),res+=a[i][id[0]];
	}
	for(int cur=0;cur<3;cur++){
		while((int)q[cur].size()>n/2)
			res+=q[cur].top(),q[cur].pop();
		while(q[cur].size()) q[cur].pop();
	}
	printf("%d\n",res);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--) HitachiMako();
	return 0;
} 
