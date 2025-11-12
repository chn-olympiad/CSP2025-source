#include <bits/stdc++.h>
//#define int long long
//#define db double
using namespace std;
int n,m,k,a[15][10005],c[15],f[10005];
bool flag=1;

int find(int p){
	return p==f[p] ? p : f[p]=find(f[p]);
}

void unionf(int p,int q){
	f[find(p)]=f[find(q)];
}

struct note{
	int u,v,w;
}arr[1100005];

bool cmp(const note x,const note y){
	return x.w<y.w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin >> arr[i].u >> arr[i].v >> arr[i].w;
	if(k==0){
		sort(arr+1,arr+m+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(find(arr[i].u)!=find(arr[i].v)){
				unionf(arr[i].u,arr[i].v);
				cnt++;
				ans+=arr[i].w;
			}
			if(cnt==n-1){
				cout << ans;
				return 0;
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		if(c[i]) flag=0;
		for(int j=1;j<=n;j++) cin >> a[i][j];
	}
	if(flag){
		for(int i=1;i<=k;i++)
			for(int j=2;j<=n;j++)
				for(int l=1;l<j;l++) arr[++m].u=j,arr[m].v=l,arr[m].w=a[i][j]+a[i][l];
		sort(arr+1,arr+m+1,cmp);
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(find(arr[i].u)!=find(arr[i].v)){
				unionf(arr[i].u,arr[i].v);
				cnt++;
				ans+=arr[i].w;
			}
			if(cnt==n-1){
				cout << ans;
				return 0;
			}
		}
	}
	return 0;
}
