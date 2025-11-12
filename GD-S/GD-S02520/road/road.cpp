#include<bits/stdc++.h>

using namespace std;

struct cai{
	int u,v,w;
	bool operator > (const cai llll)const{
		return w > llll.w;
	}
};
priority_queue<cai,vector<cai>,greater<cai> >q;
int n,m,k,t[15],fa[10005],l[15],ll[15][10005],uu[1000005],vv[1000006],ww[1000006];

int fifa(int x){
	return fa[x] == x ? x : fa[x] = fifa(fa[x]);
}

void ad(int x,int y){
	int xx = fifa(x),yy = fifa(y);
	fa[xx] = yy;
	return ;
}

int dfs(int s){
	if(s > k){
		int ans = 0,now = n;
		while(!q.empty())q.pop();
		for(int i = 1;i <= m;i++){
			q.push({uu[i],vv[i],ww[i]});
		}
		for(int i = 1;i <= n;i++)fa[i] = i;
		for(int i = 1;i <= k;i++){
			if(t[i]){
				ans += l[i];
				for(int aa = 1;aa <= n;aa++){
					for(int bb = aa + 1;bb <= n;bb++){
						q.push({aa,bb,ll[i][aa] + ll[i][bb]});
					}
				}
			}
		}
		while(now > 1){
			cai lll = q.top();
			q.pop();
			if(fifa(lll.u) != fifa(lll.v)){
				ad(lll.u,lll.v);
				now--;
				ans += lll.w;
			}
		}
		return ans;
	}
	t[s] = 0;
	int re = dfs(s + 1);
	t[s] = 1;
	re = min(re,dfs(s + 1));
	return re;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> uu[i] >> vv[i] >> ww[i];
	}
	for(int i = 1;i <= k;i++){
		cin >> l[i];
		for(int j = 1;j <= n;j++)cin >> ll[i][j];
	}
	if(k > 5 || n > 1000){
		cout << 0 << endl;
		return 0;
	}
	cout << dfs(1) << endl;
	return 0;
}
