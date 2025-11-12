#include<bits/stdc++.h>
#define int long long
using namespace std;

int fy[10010],bcnt=0;
int f[10010],ans=0;
int n,m,k;

struct bian{
	int s,e,w;
}b[22000010];

bool cmp(bian a,bian b){
	return a.w<b.w; 
}

int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}

void klsker(){
	int js=1; 
	for(int i=1;i<=bcnt;i++){
		int fx,fy;
		fx=find(b[i].s);
		fy=find(b[i].e);
		if(fx!=fy){
			js++;
			ans+=b[i].w;
			f[fx]=fy;
		}
		if(js==n)break;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int a,c,d;
		cin>>a>>c>>d;
		bcnt++;
		b[bcnt].s=a;
		b[bcnt].e=c;
		b[bcnt].w=d;
	}
	for(int i=1;i<=k;i++){
		int q;
		cin>>q;
		for(int j=1;j<=n;j++)cin>>fy[j];
		for(int j=1;j<=n;j++){
			for(int o=j+1;o<=n;o++){
				bcnt++;
				b[bcnt].s=j;
				b[bcnt].e=o;
				b[bcnt].w=q+fy[j]+fy[o];
			}
		}
	}
	sort(b+1,b+bcnt+1,cmp);
	klsker();
	cout<<ans;
	return 0;
}

