#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}a[N],mpa[N],mpb[N],mpc[N];
bool cmpa(node a,node b){
	return a.a-max(a.b,a.c)<b.a-max(b.b,b.c);
}
bool cmpb(node a,node b){
	return a.b-max(a.a,a.c)<b.b-max(b.a,b.c);
} 
bool cmpc(node a,node b){
	return a.c-max(a.a,a.b)<b.c-max(b.a,b.b);
}
void solve()
{
	int n;
	cin>>n;
	long long ans=0;
	int cnta=0,cntb=0,cntc=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
			cnta++;
			ans+=a[i].a;
			mpa[cnta]=a[i];
			continue;
		}
		if(a[i].b>a[i].a&&a[i].b>=a[i].c){
			cntb++;
			ans+=a[i].b;
			mpb[cntb]=a[i];
			continue;
		}
		cntc++;
		mpc[cntc]=a[i];
		ans+=a[i].c; 
	}
	if(cnta>n/2){
		sort(mpa+1,mpa+cnta+1,cmpa);
		for(int i=1;i<=cnta;i++){
			ans-=mpa[i].a;
			ans+=max(mpa[i].b,mpa[i].c);
			if(cnta-i<=n/2){
				break;
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	if(cntb>n/2){
		sort(mpb+1,mpb+cntb+1,cmpb);
		for(int i=1;i<=cntb;i++){
			ans-=mpb[i].b;
			ans+=max(mpb[i].a,mpb[i].c);
			if(cntb-i<=n/2){
				break;
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	if(cntc>n/2){
		sort(mpc+1,mpc+cntc+1,cmpc);
		for(int i=1;i<=cntc;i++){
			ans-=mpc[i].c;
			ans+=max(mpc[i].a,mpc[i].b);
			if(cntc-i<=n/2){
				break;
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	cout<<ans<<'\n';
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		solve();
	}	
	return 0;
 } 
