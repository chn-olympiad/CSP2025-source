//May all the beauty be blessed.
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int t;
int n;
int a[100010][5],ans;
int v[100010],cnt[5];
priority_queue<pii> p;

void sol(int x){
	int sum=cnt[x];
	for(int i=1;i<=n;i++){
		if(v[i]!=x) continue;
		p.push({max(a[i][(x+1)%3],a[i][(x+2)%3])-a[i][x],i});
	}
	
	for(int i=1;i<=sum-n/2;i++){
		int y=0;
		int j=p.top().se;
		if(a[j][(x+1)%3]-a[j][x]==p.top().fi) y=(x+1)%3;
		else y=(x+2)%3;
		v[j]=y;
		
		p.pop();
	}
	
}
void clear(){
	while(p.size()) p.pop();
	for(int i=1;i<=n;i++) v[i]=0;
	ans=0;
	for(int i=0;i<=2;i++) cnt[i]=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		
		for(int i=1;i<=n;i++) p.push({a[i][1]-a[i][0],i});
		
		for(int i=1;i<=n;i++){
			if(p.top().fi<=0) break;
			v[p.top().se]=1;
			p.pop();
		}
		while(p.size()) p.pop();
		
		for(int i=1;i<=n;i++){
			p.push({a[i][2]-a[i][v[i]],i});
		}
		
		for(int i=1;i<=n/2;i++){
			if(p.top().fi<=0) break;
			v[p.top().se]=2;
			p.pop();
		}
		while(p.size()) p.pop();
		
		for(int i=1;i<=n;i++){
			cnt[v[i]]++;
		}
		
		int w=-1;
		for(int i=0;i<=2;i++) if(cnt[i]>n/2) w=i;
		
		if(w!=-1) sol(w);
		
		for(int i=1;i<=n;i++) ans+=a[i][v[i]];
		
		cout<<ans<<'\n';
		clear();
	}
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

*/
