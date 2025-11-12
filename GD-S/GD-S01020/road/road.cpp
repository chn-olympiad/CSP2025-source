#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct roadw{
	LL city1;
	LL city2;
	LL price;
};
bool cmp(roadw x,roadw y){
	return x.price<y.price;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	LL n=0,m=0,k=0;
	LL ans=0;
	LL town[k+1][6]={};
	cin>>n>>m>>k;
	roadw roadv[n+n*m+1]={};
	for(int i=1;i<=m;i++){
		cin>>roadv[i].city1>>roadv[i].city2>>roadv[i].price;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>town[i][j];
		}
		for(int j=2;j<=n;j++){
			roadv[m+i].city1=j;
			roadv[m+i].city2=n+i;
			roadv[m+i].price=town[i][j]+town[i][1];
		}
	}
	LL now_through=0;
	LL city_canbeused[n+n*m+1]={};
	sort(roadv,roadv+n+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		ans+=roadv[i].price;
	} 
	cout << ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
