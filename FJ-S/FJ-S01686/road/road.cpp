#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
const int N=1e4+1e3;

struct node{
	int x,y,w;
}a[M],p[N];
int n,m,k;
long long ans=INT_MAX;
int c[15][N],aas[N],cnt;
bool book[15],aa[N],kc[15];
bool cmp(node l,node r){
	return l.x<r.x;
}
void tc(int cc,int pp){
	memset(aa,0,sizeof(aa));
	memset(aas,0,sizeof(aas));
	memset(kc,0,sizeof(kc));
	cnt=1;
	aa[1]=1;
	aas[++cnt]=1;
	long long sum=pp;
	if(sum>=ans) return;
//	for(int i=1;i<=k;i++)	cout<<book[i]<<" ";
//	cout<<pp<<endl;
	while(cc--){
		int st=0,ed=0,ww=INT_MAX,f=0;
		for(int i=1;i<=cnt;i++){
			for(int j=p[aas[i]].x;j<=p[aas[i]].y;j++){
				if(!aa[a[j].y] && ww>a[j].w){
					ww=a[j].w,st=i,ed=a[j].y;
				}
			}
		}
		for(int i=1;i<=k;i++){
			if(book[i]==1){
				if(kc[i]==1){
					for(int j=1;j<=cnt;j++)
						if(!aa[i] && c[i][j]<ww){
							ww=c[i][j];
							st=i,ed=j;
						}
				}else
					for(int j=1;j<=cnt;j++)
						if(c[i][aas[j]]<ww){
							ww=c[i][aas[j]];
							st=aas[j],ed=i,f=1;
						}
			}
		}
		if(f==1) kc[ed]=1;
		else aa[ed]=1,aas[++cnt]=ed;
		sum+=ww; 
//		if(pp==0){
//			cout<<st<<" "<<ed<<" "<<ww<<endl;
//		}
	}
//	cout<<sum<<" "<<pp<<endl<<endl<<endl;
	ans=min(sum,ans);
}
void dfs(int s,int num,int pp){
	if(s>k){
		tc(n+num-1,pp);
	}else{
		book[s]=0;
		dfs(s+1,num,pp);
		book[s]=1;
		dfs(s+1,num+1,pp+c[s][0]);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
		a[i+m].y=a[i].x,a[i+m].x=a[i].y,a[i+m].w=a[i].w;
	} 
	sort(a+1,a+2*m+1,cmp);
	for(int i=1;i<=2*m;i++){
		if(p[a[i].x].x==0) p[a[i].x].x=i;
		p[a[i].x].y=i;
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>c[i][j];
	int f=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)
			if(c[i][j]!=0){
				f=0;
				break;
			}
	}
	if(f && k!=0){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
