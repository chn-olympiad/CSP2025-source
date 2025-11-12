#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7;
struct fz{
	int x,y,w,flag;
}a[N];
int n,m,k,c[15],s[15][15];
int ld[N];
bool cmp(fz x,fz y){
	return x.w<y.w;
}
int find(int x){
	if (ld[x]!=x){
		ld[x]=find(ld[x]);
	}
	return ld[x];
}
int K(){
	for (int i=1;i<=n;i++) ld[i]=i;
	sort(a+1,a+m+1,cmp);
	int cnt=0,sum=0;
	for (int i=1;i<=m;i++){
		int ld1=find(a[i].x);
		int ld2=find(a[i].y);
		if (ld1!=ld2){
			ld[ld2]=ld1;
			sum+=a[i].w;
			cnt++;
		}
		if (cnt==n-1) break;
	}
	return sum;
}
map<pair<int,int> ,int> mp;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
		a[i].flag=0;
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
		mp[{a[i].x,a[i].y}]=a[i].w;
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	if (k==0) cout<<K();
	else{
		for (int w=1;w<=k;w++){
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					if (mp[{i,j}]==0||c[w]+s[w][i]+s[w][j]<mp[{i,j}]){
						a[++m]={i,j,c[w]+s[w][i]+s[w][j],w};
					}
				}
			}
		}
		cout<<K();
	}
	return 0;
}
