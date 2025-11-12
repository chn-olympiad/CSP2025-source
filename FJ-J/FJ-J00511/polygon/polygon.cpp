#include <bits/stdc++.h>
#define int long long
#define tu pair<int,int>
#define t first
#define u second
using namespace std;

const int MAXN=5005,p=998244353;

int a[MAXN];
int n;

// s起始点 e边数 sum累加和 
int bfs(){
	queue<tu> q;
	q.push({0,0});
	int e=0,ans=0;
	while (q.size()){
		for (int i=q.size();i>0;i--){
			tu cur=q.front();
			q.pop();
			ans=(ans+(e>=3&&cur.u>2*a[cur.t]))%p;
			for (int i=cur.t+1;i<=n;i++){
				q.push({i,cur.u+a[i]});
			}
		}
		e++;
	}
	return ans;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d",bfs());
	
	return 0;
}
