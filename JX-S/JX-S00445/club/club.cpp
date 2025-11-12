#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=2e9+10;
int n,a[maxn][3],b[maxn],c[maxn];
int cnt[3];
int calc(){int s=0;for(int i=1;i<=n;i++) s+=a[i][c[i]];return s;}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=0;j<=2;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<=2;i++) cnt[i]=0;
	for(int i=1;i<=n;i++){
		b[i]=0;if(a[i][1]>a[i][0]) b[i]=1;
		if(a[i][2]>a[i][b[i]]) b[i]=2;
		c[i]=b[i];
	}for(int i=1;i<=n;i++) cnt[c[i]]++;
	int mp=0;if(cnt[1]>cnt[0]) mp=1;if(cnt[2]>cnt[mp]) mp=2;
	if(cnt[mp]*2<=n){printf("%d\n",calc());return ;}
	int x=(mp+1)%3,y=(mp+2)%3;
	priority_queue<pair<int,int> > q;
	for(int i=1;i<=n;i++) if(c[i]==mp){
		if(a[i][mp]-a[i][x]<=a[i][mp]-a[i][y]){
			q.push({-(a[i][mp]-a[i][x]),i});
		}else{
			q.push({-(a[i][mp]-a[i][y]),i});
		}
	}int u=0,v=0;
	while(cnt[mp]*2>n){
		u=q.top().second,v=-q.top().first;q.pop();
		cnt[mp]--;
		if(a[u][mp]-a[u][x]<=a[u][mp]-a[u][y]) c[u]=x;
		else c[u]=y;
		cnt[c[u]]++;
	}if(cnt[x]*2<=n&&cnt[y]*2<=n){printf("%d\n",calc());return ;}
	int p=c[u],o=(p==x?y:x),s1=INF,r1=0,s2=INF,r2=0;
	for(int i=1;i<=n;i++) if(c[i]==p){
		if(a[i][p]-a[i][o]<s1) r1=i,s1=a[i][p]-a[i][o];
	}
	for(int i=1;i<=n;i++) if(c[i]==mp){
		if(a[i][mp]-a[i][o]<s2) r2=i,s2=a[i][mp]-a[i][o];
	}s2-=v;
	if(s1>=s2) c[r1]=o;
	else c[r2]=o,c[u]=mp;
	printf("%d\n",calc());
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}
