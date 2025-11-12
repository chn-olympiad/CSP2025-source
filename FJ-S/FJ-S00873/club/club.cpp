#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010][4];
ll bm1[200010];
ll bm2[200010];
ll bm3[200010];
bool cmp(ll a,ll b){
	return a>b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;cin>>t;
	while(t--) {
		
		ll x=0,y=0,z=0,ans=0;;
		memset(bm1,0,sizeof(bm1));
		memset(bm2,0,sizeof(bm2));
		memset(bm3,0,sizeof(bm3));
		ll b1=0,b2=0,b3=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
				x++;
				b1++;
				bm1[b1]=a[i][1]-max(a[i][2],a[i][3]);
			} else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				y++;
				b2++;
				bm2[b2]=a[i][2]-max(a[i][1],a[i][3]);
			} else {
				z++;
				b3++;
				bm3[b3]=a[i][3]-max(a[i][2],a[i][1]);
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout<<ans<<'\n';
		}else if(x>n/2){
			sort(bm1+1,bm1+b1+1);
			for(int i=1;x>n/2;i++){
				ans-=bm1[i];
				x--;
			}
			cout<<ans<<'\n';
			
		}else if(y>n/2){
			sort(bm2+1,bm2+b2+1);
			for(int i=1;y>n/2;i++){
				ans-=bm2[i];
				y--;
			}
			cout<<ans<<'\n';
			
		}else if(z>n/2){
			sort(bm3+1,bm3+b3+1);
			for(int i=1;z>n/2;i++){
				ans-=bm3[i];
				z--;
			}
			cout<<ans<<'\n';
			
		}
		
		
	}

	return 0;
}

