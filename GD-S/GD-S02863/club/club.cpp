#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct ly{
	int id,cha,maxa;
} e[100010];
int cl[10];
bool cmp(ly x,ly y){
	if(x.cha==y.cha) return x.maxa>y.maxa;
	return x.cha>y.cha;
}
int a[100010][5];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int maxx=0,minx=0x3f3f3f3f,minid,maxid,aid;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(maxx<a[i][j]){
				maxx=a[i][j];
				maxid=j;
			}
			if(minx>a[i][j]){
				minx=a[i][j];
				minid=j;
			}
		}
		for(int j=1;j<=3;j++){
			if(j!=maxid&&j!=minid) aid=j;
		}
		e[i].id=i;
		e[i].maxa=maxx;
		e[i].cha=(maxx-a[i][aid]);
	}
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++){
		int maxx=0,maxid;
		for(int j=1;j<=3;j++){
			if(maxx<a[e[i].id][j]){
				maxx=a[e[i].id][j];
				maxid=j;
			}
		}
		ans+=maxx;
		cl[maxid]++;
		if(cl[maxid]>=n/2){
			for(int j=1;j<=n;j++){
				a[j][maxid]=0;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		memset(cl,0,sizeof(cl));
		ans=0;
		solve();
	}
	return 0;
}
