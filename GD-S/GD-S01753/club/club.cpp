#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
int T,n,m,a[N],b[N],c[N],mx,k,cnt;
ll ans;
vector<int> x,y,z,v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,x.clear(),y.clear(),z.clear(),k=n/2,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i],mx=max(a[i],max(b[i],c[i]));
			if(mx==a[i]) x.push_back(i);
			else if(mx==b[i]) y.push_back(i);
			else z.push_back(i);
			ans+=mx;
		}
		if(x.size()<=k&&y.size()<=k&&z.size()<=k){
			cout<<ans<<'\n';
			continue;
		}
		if(x.size()>k) v=x,cnt=1;
		else if(y.size()>k) v=y,cnt=2;
		else v=z,cnt=3;
		for(int i=0;i<v.size();i++){
			if(cnt==1) v[i]=a[v[i]]-max(b[v[i]],c[v[i]]);
			if(cnt==2) v[i]=b[v[i]]-max(c[v[i]],a[v[i]]);
			if(cnt==3) v[i]=c[v[i]]-max(a[v[i]],b[v[i]]);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size()-k;i++) ans-=v[i];
		cout<<ans<<'\n';
	}
	return 0;
}
