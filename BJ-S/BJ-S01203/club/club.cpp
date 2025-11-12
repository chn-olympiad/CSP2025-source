#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
struct node{
	int a,b,c;
	ll mx,sum;
};
node a[maxn];
int tot[maxn];
bool cmp(node x,node y){
	if(x.mx!=y.mx)return x.mx>y.mx;
	else return x.sum>y.sum;
}
void solve(int n){
	for(int i=1;i<=n;i++){
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			tot[i]=1;
		else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			tot[i]=2;
		else tot[i]=3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].sum=a[i].a+a[i].b+a[i].c;
			a[i].mx=max(max(a[i].a,a[i].b),a[i].c);
		}
		sort(a+1,a+n+1,cmp);
		solve(n);
		for(int i=1;i<=n;i++){
			if(cnt1==n/2){
				for(int j=i;j<=n;j++){
					a[j].a=-1;
					a[j].mx=max(a[j].b,a[j].c);
					a[j].sum=a[j].b+a[j].c;
				}
				sort(a+i,a+n+1,cmp);
				solve(n);
				cnt1=0;
			}
			if(cnt2==n/2){
				for(int j=i;j<=n;j++){
					a[j].b=-1;
					a[j].mx=max(a[j].a,a[j].c);
					a[j].sum=a[j].a+a[j].c;
				//	cout<<"a["<<j<<"].mx="<<a[j].mx<<'\n';
				}
				sort(a+i,a+n+1,cmp);
				solve(n);
				cnt2=0;
			}if(cnt3==n/2){
				for(int j=i;j<=n;j++){
					a[j].c=-1;
					a[j].mx=max(a[j].b,a[j].a);
					a[j].sum=a[j].b+a[j].a;
				}
				sort(a+i,a+n+1,cmp);
				solve(n);
				cnt3=0;
			}
			if(a[i].mx==a[i].a){
				cnt1++;
				ans+=a[i].mx;
				cout<<"ans+01="<<ans<<'\n';
			}else if(a[i].mx==a[i].b){
				cnt2++;
				ans+=a[i].mx;
				cout<<"ans+02="<<ans<<'\n';
			}else{
				cnt3++;
				ans+=a[i].mx;
				cout<<"03="<<a[i].mx<<'\n';
				cout<<"ans+03="<<ans<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
}
