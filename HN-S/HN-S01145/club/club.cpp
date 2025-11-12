#include<bits/stdc++.h>
using namespace std;
struct str{int f,id;}a[100001],b[100001],c[100001];
int d[100001][3],ans;
bool vis[100001];
bool cmp(str a,str b){
	if(a.f==b.f)return a.id<b.id;
	return a.f>b.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,X;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		int n;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i][0]>>d[i][1]>>d[i][2];
			a[i].f=d[i][0];a[i].id=i;
			b[i].f=d[i][1];b[i].id=i;
			c[i].f=d[i][2];c[i].id=i;
		}
		int bm1=0,bm2=0,bm3=0;
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].f>=d[a[i].id][1]&&a[i].f>=d[a[i].id][2]&&vis[a[i].id]==0){
				bm1++;ans+=a[i].f;vis[a[i].id]=1;cout<<i<<' ';
			}
			if(bm1==n/2)break;
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			if(b[i].f>=d[b[i].id][0]&&b[i].f>=d[b[i].id][2]&&vis[b[i].id]==0){
				bm2++;ans+=b[i].f;vis[b[i].id]=1;cout<<i<<' ';
			}
			if(bm2==n/2)break;
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			if(c[i].f>=d[c[i].id][1]&&c[i].f>=d[c[i].id][2]&&vis[c[i].id]==0){
				bm3++;ans+=c[i].f;vis[c[i].id]=1;cout<<i<<' ';
			}
			if(bm3==n/2)break;
		}
		cout<<endl;
		cout<<ans<<'\n';
	}
	return 0;
}
