#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
struct road{
	int u,v,w;
}r[1000010];

struct city{
	int c;
	int a[10010];
}s[20];
bool cmp(road x,road y){
	return x.w < y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int b[10010]={};
	cin >> n >> m >> k;
	for( int i=1;i<=m;i++){
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin >> s[i].c;
		for(int j=1;j<=n;j++){
			cin >> s[i].a[j];
		}
	}
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=n;i++){
		b[i] = i;
	}
	for(int i=1;i<=m;i++){
		int x=r[i].u,y=r[i].v;
		if( b[y] != -1 || b[x] != -1 ){
			b[y] = -1;
			b[x] = -1;
			cout << x << " " << y << endl;
			ans += r[i].w;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

