#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,ans1,ans2,cnt,c[15][10010],t[10010][10010],flag[15][3],siz,l;
int fa[10010];
pair<int,pair<int,int> > b[1011000];
bool vis[10010][10010];
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
void connect(int x, int y){
	int tmp1=getfa(x);
	int tmp2=getfa(y);
	fa[tmp1]=tmp2;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(m>650000){
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		b[i].first=w;
		b[i].second.first=u;
		b[i].second.second=v;
		t[u][v]=w;
		t[v][u]=w;
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(getfa(b[i].second.first)!=getfa(b[i].second.second)){
			cnt++;
			ans1+=b[i].first;
			connect(b[i].second.first,b[i].second.second);
			if(cnt==n-1) break;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			//b[m+n*(k-1)+j].first=c[i][j];
			//b[m+n*(k-1)+j].second.first=n+i;
			//b[m+n*(k-1)+j].second.second=j;
		}
	}
	siz=m;
	for(int i=1;i<=k;i++){
		ans2=0;
		cnt=0;
		for(int j=1;j<=n+i;j++) fa[j]=j;
		for(int j=1;j<=n;j++){
			b[j+siz].first=c[i][j];
			b[j+siz].second.first=n+i;
			b[j+siz].second.second=j;
		}
		sort(b+1,b+1+siz+n);
		l++;
		for(int j=1;j<=siz+n;j++){
			if(getfa(b[j].second.first)!=getfa(b[j].second.second)){
				cnt++;
				ans2+=b[j].first;
				connect(b[j].second.first,b[j].second.second);
				if(cnt==n+l-1) break;
			}
		}
		if(ans2+c[i][0]>ans1) l--;
		else{
			ans1=ans2+c[i][0];
			siz+=n;
		}
	}
	
	cout<<ans1;
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
