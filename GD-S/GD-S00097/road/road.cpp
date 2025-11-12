#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=1e6+10;
struct aaa{
	int a,b,c;
}a[M],b[M],d[N][20];
int n,m,k,f[N],c[N],ans,cnt;
bool cmp(aaa a,aaa b){
	return a.c<b.c;
}int fa(int x){
	if(x==f[x]){
		return x;
	}f[x]=fa(f[x]);
	return f[x];
}void ff(int x){
	if(x==0){
		for(int i=1;i<=m;i++){
			cnt++;
			b[cnt]=a[i];
		}
	} else{
		for(int i=1;i<=n;i++){
			cnt++;
			b[cnt]=d[i][x];
		}
	}
}bool ok[21],nw[21],w[21];
int mi(){
	sort(b+1,b+1+cnt,cmp);
	int ret=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=cnt;i++){
		int x=b[i].a;
		int y=b[i].b;
		int z=b[i].c;
		if(fa(x)==fa(y))
			continue;
		ret+=z;
		f[fa(x)]=fa(y);
	}return ret;
}int q(){
	int ret=0;
	cnt=0;
	for(int j=0;j<=k;j++){
		if(nw[j]){
			ff(j);
			ret+=c[j];
		}
	}ret+=mi();
	return ret;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}sort(a+1,a+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x=a[i].a;
		int y=a[i].b;
		int z=a[i].c;
		if(fa(x)==fa(y))
			continue;
		cnt++;
		ans+=z;
		b[cnt].a=x;
		b[cnt].b=y;
		b[cnt].c=z;
		f[fa(x)]=fa(y);
	}for(int i=1;i<=cnt;i++){
		a[i]=b[i];
	}m=cnt;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1,x;i<=n;i++){
			cin>>x;
			d[i][j].a=n+j;
			d[i][j].b=i;
			d[i][j].c=x;
		}
	}ok[0]=true;
	nw[0]=1;
	for(int i=1;i<pow(2,k);i++){
		int x=i;
		bool A=false;
		for(int j=1;j<=k;j++){
			nw[j]=x%2;
			x>>=1;
			if(nw[j]==0&&c[j]==0){
				A=true;
			}
		}if(A)continue;
		ans=min(ans,q());
	}
	cout<<ans;
}/*m->n

*/
