#include<bits/stdc++.h>
using namespace std;
const int N =100005;
int n,a[N][3],ma,u1,u2,sz[3],xz,ans,q,qi,b[N];
vector<int> v[3];
void prians(int x){
	printf("%d",x);
	if(qi<q-1)printf("\n");
}
void solve(){
	for(int i=0;i<3;i++)v[i].clear();
	scanf("%d",&n);
	xz=n/2;ans=0;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])v[0].push_back(i);
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])v[1].push_back(i);
		else v[2].push_back(i);
	}
	for(int i=0;i<3;i++){
		sz[i]=v[i].size();
		for(int j=0;j<sz[i];j++)ans+=a[v[i][j]][i];
	}
	if(sz[0]<=xz&&sz[1]<=xz&&sz[2]<=xz){prians(ans);return;}
	if(sz[0]>xz){ma=0;u1=1;u2=2;}
	if(sz[1]>xz){ma=1;u1=0;u2=2;}
	if(sz[2]>xz){ma=2;u1=0;u2=1;}
	for(int i=0;i<sz[ma];i++)b[i]=a[v[ma][i]][ma]-max(a[v[ma][i]][u1],a[v[ma][i]][u2]);
	sort(b,b+sz[ma]);
	for(int i=0;i<sz[ma]-xz;i++)ans-=b[i];
	prians(ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&q);
	for(qi=0;qi<q;qi++)solve();
	return 0;
}
