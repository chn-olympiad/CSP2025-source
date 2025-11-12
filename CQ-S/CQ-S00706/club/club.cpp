#include<bits/stdc++.h>
using namespace std;
int t,n;
#define int long long
struct node{
	int a,b,c,id,maxn;
}a[100005],sum[100005];
bool cmp(node x,node y){return x.maxn>y.maxn;}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int aa=0,bb=0,cc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
		for(int i=1;i<=n;i++){
			sum[i].a=a[i].a-max(a[i].b,a[i].c);
			sum[i].b=a[i].b-max(a[i].a,a[i].c);
			sum[i].c=a[i].c-max(a[i].a,a[i].b);
			sum[i].maxn=max({sum[i].a,sum[i].b,sum[i].c});
			sum[i].id=i;
		}
		sort(sum+1,sum+1+n,cmp);
		for(int i=1;i<=n;i++){
			int x=sum[i].id,id;
			if(a[x].a>=a[x].b&&a[x].a>=a[x].c) id=1;
			else if(a[x].b>=a[x].c) id=2;
			else id=3;
			if(id==1){
				if(aa<n/2) aa++,ans+=a[x].a;
				else{
					if(a[x].b>a[x].c) bb++,ans+=a[x].b;
					else cc++,ans+=a[x].c;
				}
			}
			if(id==2){
				if(bb<n/2) bb++,ans+=a[x].b;
				else{
					if(a[x].a>a[x].c) aa++,ans+=a[x].a;
					else cc++,ans+=a[x].c;
				}
			}
			if(id==3){
				if(cc<n/2) cc++,ans+=a[x].c;
				else{
					if(a[x].b>a[x].a) bb++,ans+=a[x].b;
					else aa++,ans+=a[x].a;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
