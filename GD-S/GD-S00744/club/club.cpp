#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][3],d[3][100005],v[3],tot;
bool cmp(ll x, ll y){
	return a[x][2]-a[x][1]<a[y][2]-a[y][1];
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		v[0]=v[1]=v[2]=tot=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",a[i],a[i]+1,a[i]+2);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				d[0][++v[0]]=i;
				tot+=a[i][0];
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				d[1][++v[1]]=i;
				tot+=a[i][1];
			}else{
				d[2][++v[2]]=i;
				tot+=a[i][2];
			}
		}for(ll i=1;i<=n;i++){
			sort(a[i],a[i]+3);
		}//for(ll i=0;i<3;i++,putchar('\n'))for(ll j=1;j<=v[i];j++)printf("%lld ",d[i][j]);
		for(ll i=0;i<3;i++){
			if(v[i]*2>n){
				sort(d[i]+1,d[i]+v[i]+1,cmp);
				for(ll j=1;j<=v[i]-n/2;j++){
					tot+=a[d[i][j]][1]-a[d[i][j]][2]; 
				}break;
			}
		}printf("%lld\n",tot);
	} 
	return 0;
}

