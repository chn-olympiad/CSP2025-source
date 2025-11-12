//ACed at 16:10
//tm laozi debug 50min 
//I love you CCF
//csp2025 rp++
//Don't fuck me CCF
//last year 100pts im joker
//nayz Funny_Congee rp++
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100;
int n,m,k,c[11],fa[N];
int ans=0x7fffffffffffffff,sum;
struct line{
	int u,v,w;
	bool operator<(const line&rhs)const{
		return w<rhs.w;
	}
}cit[N*100],t[11][N],vil[N];
int father(int x){
	if(fa[x]==x)return x;
	return (fa[x]=father(fa[x]));
}
int get_line(int st){
	int kn=0,vis[11],cnt[11],minn,ct;
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=10;i++)
		if(st&(1<<(i-1)))
			vis[++kn]=i,sum+=c[i];
	for(int i=1,j;i<=n+kn-1;i++){
		minn=0x7fffffffffffffff,ct=0;
		for(j=1;j<=kn;j++)
			if(cnt[j]+1<=n&&t[vis[j]][cnt[j]+1].w<minn){
				minn=t[vis[j]][cnt[j]+1].w;
				ct=j;
			}
		cnt[ct]++;
		vil[i]=t[vis[ct]][cnt[ct]];
	}
	return kn;
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>cit[i].u>>cit[i].v>>cit[i].w;
	sort(cit+1,cit+m+1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>t[i][j].w;
			t[i][j].u=n+i;
			t[i][j].v=j;
		}
		sort(t[i]+1,t[i]+n+1);
	}
	for(int i=0,j,x,y,kn,cnt1,cnt2;i<(1<<k);i++){
		sum=0;cnt1=cnt2=1;
		kn=get_line(i);
		for(j=1;j<=n+k;j++)fa[j]=j;
		for(j=1;j<=n+kn-1;){
			if(cit[cnt1].w<vil[cnt2].w||i==0){
				x=father(cit[cnt1].u);
				y=father(cit[cnt1].v);
				if(x!=y){
					fa[x]=y;
					sum+=cit[cnt1].w;
					j++;
				}
				cnt1++;
			}else{
				x=father(vil[cnt2].u);
				y=father(vil[cnt2].v);
				if(x!=y){
					fa[x]=y;
					sum+=vil[cnt2].w;
					j++;
				}
				cnt2++;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
