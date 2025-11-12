#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],sa[N],sb[N],sc[N],mx[N],nx[N];
bool cmp(int a,int b){
	return mx[a]-nx[a]<mx[b]-nx[b];
}
void solve(){
	cin>>n;
	int cnta=0,cntb=0,cntc=0;
	long long ans=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if (c[i]>max(a[i],b[i])){
			sc[++cntc]=i;
			ans+=c[i];
			mx[i]=c[i];
			nx[i]=max(a[i],b[i]);
		}else if (a[i]>b[i]){
			sa[++cnta]=i;
			ans+=a[i];
			mx[i]=a[i];
			nx[i]=max(c[i],b[i]);
		}else{
			sb[++cntb]=i;
			ans+=b[i];
			mx[i]=b[i];
			nx[i]=max(a[i],c[i]);
		}
	}
	if (cntc>n/2){
		sort(sc+1,sc+cntc+1,cmp);
		for (int i=1;i<=cntc-n/2;i++){
			ans-=mx[sc[i]]-nx[sc[i]];
		}
	}
	if (cntb>n/2){
		sort(sb+1,sb+cntb+1,cmp);
		for (int i=1;i<=cntb-n/2;i++){
			ans-=mx[sb[i]]-nx[sb[i]];
		}
	}
	if (cnta>n/2){
		sort(sa+1,sa+cnta+1,cmp);
		for (int i=1;i<=cnta-n/2;i++){
			ans-=mx[sa[i]]-nx[sa[i]];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
