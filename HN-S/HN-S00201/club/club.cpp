#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define qwe(i,l,r) for(int i=l;i<=r;i++)
#define ewq(i,r,l) for(int i=r;i>=l;i--)
int n,ans,a[N],b[N],c[N],t[N],tot,vis[N],sum1,sum2,sum3;
void solve(){
	tot=sum1=sum2=sum3=ans=0;
	cin>>n;
	qwe(i,1,n)cin>>a[i]>>b[i]>>c[i];
	qwe(i,1,n){
		t[i]=1e9+7;
		if(a[i]>=b[i]&&a[i]>=c[i]){
			ans+=a[i];
			sum1++;
			vis[i]=1;
		}else if(b[i]>=a[i]&&b[i]>=c[i]){
			ans+=b[i];
			sum2++;
			vis[i]=2;
		}else if(c[i]>=a[i]&&c[i]>=b[i]){
			ans+=c[i];
			sum3++;
			vis[i]=3;
		}
	}
	if(sum1>(n>>1)){
		qwe(i,1,n)if(vis[i]==1)t[++tot]=min(a[i]-b[i],a[i]-c[i]);
		sort(t+1,t+1+tot);
		qwe(i,1,tot){
			ans-=t[i];
			sum1--;
			if(sum1<=(n>>1))break;
		}
	}else if(sum2>(n>>1)){
		qwe(i,1,n)if(vis[i]==2)t[++tot]=min(b[i]-a[i],b[i]-c[i]);
		sort(t+1,t+1+tot);
		qwe(i,1,tot){
			ans-=t[i];
			sum2--;
			if(sum2<=(n>>1))break;
		}
	}else if(sum3>(n>>1)){
		qwe(i,1,n)if(vis[i]==3)t[++tot]=min(c[i]-a[i],c[i]-b[i]);
		sort(t+1,t+1+tot);
		qwe(i,1,tot){
			ans-=t[i];
			sum3--;
			if(sum3<=(n>>1))break;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;cin>>T;
	while(T--)solve();
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
