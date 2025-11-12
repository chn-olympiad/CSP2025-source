#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,num,g,zhan,s[100005],ma[1005][1005],h;bool f[100005];
struct road{
	int u,v,w;
}a[1000005];
bool cmp(road x,road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		
	}
	for (int i = 1;i <= k;i++){
		//cout << "miao" << endl;
		cin >> zhan;
		for (int j = 1;j <= n;j++){
			cin >> s[j];
		}
		for (int j = 1;j < n;j++){
			for (int z = j+1;z <= n;z++){
				h++;
				a[h+m].u = j;a[h+m].v = z;a[h+m].w = s[j]+s[z]+zhan;
			}
		}
	}
	//for (int i = 1;i <= m+h;i++){
	//	cout << a[i].u << " " << a[i].v << " " << a[i].w << endl;
	//}
	sort(a+1,a+m+h+1,cmp);
	g = 1;
	while(num<n){
		//cout << a[g].u << " " << a[g].v << endl;
		if(f[a[g].u]==1&&f[a[g].v]==1){
			g++;
			continue;
		}
		ans+=a[g].w;
		if(f[a[g].u]==0){
			f[a[g].u]=1;
			num++;
		}
		if(f[a[g].v]==0){
			f[a[g].v]=1;
			num++;
		}
		g++;
	}
	cout << ans;
	return 0;
}
