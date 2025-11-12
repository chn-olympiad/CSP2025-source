#include<bits/stdc++.h>
using namespace std;

int n,m,k,pre[10005],c[12][10005];
long long ans = 0;

struct cl{
	int u,v,w;
}h[50000005];

bool cmp1(cl a,cl b){
	return a.w < b.w;
}

int find(int x){
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}

int Kr(){
	int cnt = 0,i = 1;
	for(int i=1;i<=m;i++){
		int fx = find(h[i].u);
		int fy = find(h[i].v);
		if(fx == fy) continue;
		ans += h[i].w;
		pre[fx] = fy;
		cnt++;
		if(cnt == n)
			break;
	}
	return 0;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		pre[i] = i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&h[i].u,&h[i].v,&h[i].w);
	}
	if(k == 0){
		sort(h+1,h+m+1,cmp1);
		Kr();
		cout<<ans;
		return 0;
	}
	else {
		int o1 = m;
		for(int i=1;i<=k;i++){
			cin>>c[i][0];
			for(int j=1;j<=n;j++){
				scanf("%d",&c[i][j]);
				for(int l=1;l<j;l++){
					h[o1].u = j;
					h[o1].v = l;
					h[o1].w = c[i][j] + c[i][l];
					o1++;
				}
			}
		}
		sort(h+1,h+o1,cmp1);
			Kr();
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
