#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],d[N],e[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	int cnt1=0,cnt2=0,cnt3=0,ans=0;
	for(int i=1;i<=n;i++){
		int x=max(a[i],max(b[i],c[i]));
		ans+=x;
		if(x==a[i]){
			cnt1++;
			d[i]=1;
		}
		else if(x==b[i]){
			cnt2++;
			d[i]=2;
		}
		else if(x==c[i]){
			cnt3++;
			d[i]=3;
		}
	}
	int k=max(max(cnt1,cnt2),cnt3);
	if(k<=n/2){
		cout<<ans<<"\n";
		return ;
	}
	int g;
	if(cnt1>n/2)
		g=1;
	if(cnt2>n/2)
		g=2;
	if(cnt3>n/2)
		g=3;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(d[i]==g){
			int x,y,r;
			if(g==1)
				x=b[i],y=c[i],r=a[i];
			if(g==2)
				x=a[i],y=c[i],r=b[i];
			if(g==3)
				x=a[i],y=b[i],r=c[i];
			e[++cnt]=r-max(x,y);
		}
	sort(e+1,e+cnt+1);
	for(int i=n/2+1;i<=k;i++)
		ans-=e[i-n/2];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}