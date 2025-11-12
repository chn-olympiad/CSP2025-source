#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,sum,ans=2e18;
int f[10015],cnt[1010];
int c[15];
struct node{
	int a,b,c;
}a[1000010],b[15][10010],t[1010][10015];
bool cmp(node x,node y){
	return x.c<y.c;
}
int get(int x){ 
	if(f[x]==x) return x;
	return f[x]=get(f[x]); 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	int x;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			b[i][j]={i+n,j,x};
		}
		sort(b[i]+1,b[i]+n+1,cmp);
	}
	sort(a+1,a+m+1,cmp);
	sum=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(get(a[i].a)!=get(a[i].b)){
			f[get(a[i].a)]=get(a[i].b);
			t[0][++cnt[0]]=a[i]; 
			sum+=a[i].c;
		}
	}
	ans=min(ans,sum);
	int l,r,la,len;
	for(int i=1;i<(1<<k);i++){
		sum=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				x=j;
				la=(i^(1<<j-1));
				break;
			}
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				sum+=c[j];
			}
		}
		l=1;
		r=1;
		len=0;
		while(l<=cnt[la]||r<=n){
			if(l<=cnt[la]&&((r>n)||(t[la][l].c<b[x][r].c))) a[++len]=t[la][l++];
			else a[++len]=b[x][r++];
		}
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(int j=1;j<=len;j++){
			if(get(a[j].a)!=get(a[j].b)){
				f[get(a[j].a)]=get(a[j].b);
				t[i][++cnt[i]]=a[j];
				sum+=a[j].c;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
