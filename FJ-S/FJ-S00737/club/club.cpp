#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,ans,tot[4];
struct node{
	int a[4],f;
}a[N],V1[N],V2[N],V3[N];
bool cmp(node x,node y){
	return x.f>y.f;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=tot[1]=tot[2]=tot[3]=0ll;
		for(int i=1;i<=n;i++){
			cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
			a[i].f=1e18;
			int Max=max(a[i].a[1],max(a[i].a[2],a[i].a[3]));
			ans+=Max;
			if(Max==a[i].a[1]){
				a[i].f=min(a[i].a[1]-a[i].a[2],a[i].a[1]-a[i].a[3]);
				V1[++tot[1]]=a[i];
			}
			else if(Max==a[i].a[2]){
				a[i].f=min(a[i].a[2]-a[i].a[1],a[i].a[2]-a[i].a[3]);
				V2[++tot[2]]=a[i];
			}
			else{
				a[i].f=min(a[i].a[3]-a[i].a[1],a[i].a[3]-a[i].a[2]);
				V3[++tot[3]]=a[i];
			}
		}
		int t=0ll;
		if(tot[1]>n/2)t=1;
		else if(tot[2]>n/2)t=2;
		else if(tot[3]>n/2)t=3;
		if(t==1ll){
			sort(V1+1,V1+1+tot[1],cmp);
			for(int i=tot[1];i>n/2;i--)ans-=V1[i].f;
		}
		if(t==2ll){
			sort(V2+1,V2+1+tot[2],cmp);
			for(int i=tot[2];i>n/2;i--)ans-=V2[i].f;
		}
		if(t==3ll){
			sort(V3+1,V3+1+tot[3],cmp);
			for(int i=tot[3];i>n/2;i--)ans-=V3[i].f;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
