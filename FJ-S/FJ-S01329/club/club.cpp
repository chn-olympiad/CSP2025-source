#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef pair <long long,pair <long long,long long> > PII;
const int N = 1e5 + 10;
int t;
int n;
int a[N][4];
int d[4];
int s[N];
bool st[N];
int ans = 0;
bool cmp(PII a,PII b){
	return a.first > b.first;
}
void dfs(int u){
	if(u == n + 1){
		int res = 0;
		for(int i = 1;i <= n;i ++){
			res += a[i][s[i]];
		}
		ans = max(res,ans);
		return ;
	}
	for(int i = 1;i <= 3;i ++){
		if(d[i] < n / 2){
			d[i] ++;
			s[u] = i;
			dfs(u + 1);
			d[i] --;
			s[u] = 0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t --){
		ans = 0;
		scanf("%d",&n);
		if(n <= 200){
			for(int i = 1;i <= n;i ++){
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			}
			dfs(1);
			printf("%d\n",ans);
		}
		else{
			memset(st,0,sizeof st);
			priority_queue <PII> heap;
			for(int i = 1;i <= n;i ++){
				long long x,y,z;
				scanf("%lld%lld%lld",&x,&y,&z);
				heap.push({x,{1,i}});
				heap.push({y,{2,i}});
				heap.push({z,{3,i}});
			}
			int ss[4] = {0,0,0,0};
			long long res = 0;
			while(heap.size()){
				PII t = heap.top();
				heap.pop();
				if(!st[t.second.second]){
					if(ss[t.second.first] < n / 2){
						ss[t.second.first] ++;
						res += t.first;
						st[t.second.second] = true;
					}
				}
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
