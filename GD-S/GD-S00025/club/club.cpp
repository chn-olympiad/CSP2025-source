#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int x,y,z,n,t,a[N],b[N],c[N],mx[N],smx[N];
long long ans;
vector<int>v;
void solve(){
	cin>>n,ans=0,v.clear();
	x=y=z=0;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
		mx[i]=max({a[i],b[i],c[i]});
		smx[i]=a[i]+b[i]+c[i]-mx[i]-min({a[i],b[i],c[i]});
	}
	for(int i=1;i<=n;++i){
		ans+=mx[i];
		if(mx[i]==a[i]) ++x;
		else if(mx[i]==b[i]) ++y;
		else ++z;
	}
	if(x>n/2){
		x-=n/2;
		for(int i=1;i<=n;++i) if(mx[i]==a[i]) v.push_back(mx[i]-smx[i]);
		sort(v.begin(),v.end());
		for(int i=0;i<x;++i) ans-=v[i];
	}
	else if(y>n/2){
		y-=n/2;
		for(int i=1;i<=n;++i) if(mx[i]!=a[i]&&mx[i]==b[i]) v.push_back(mx[i]-smx[i]);
		sort(v.begin(),v.end());
		for(int i=0;i<y;++i) ans-=v[i];
	}
	else if(z>n/2){
		z-=n/2;
		for(int i=1;i<=n;++i) if(mx[i]!=a[i]&&mx[i]!=b[i]) v.push_back(mx[i]-smx[i]);
		sort(v.begin(),v.end());
		for(int i=0;i<z;++i) ans-=v[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}
