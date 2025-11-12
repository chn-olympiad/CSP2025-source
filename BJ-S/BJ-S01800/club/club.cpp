#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int v[5][N],k1,k2,k3;
void solve(){
	k1=k2=k3=0;
	int n;
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>y&&x>z){
			ans+=x;
			v[1][++k1]=x-max(y,z);
		}else if(y>z){
			ans+=y;
			v[2][++k2]=y-max(x,z);
		}else {
			ans+=z;
			v[3][++k3]=z-max(x,y);
		}
	}
	sort(v[1]+1,v[1]+1+k1);
	sort(v[2]+1,v[2]+1+k2);
	sort(v[3]+1,v[3]+1+k3);
	for(int i=1;i+n/2<=k1;i++){
		ans-=v[1][i];
	}
	for(int i=1;i+n/2<=k2;i++){
		ans-=v[2][i];
	}
	for(int i=1;i+n/2<=k3;i++){
		ans-=v[3][i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}