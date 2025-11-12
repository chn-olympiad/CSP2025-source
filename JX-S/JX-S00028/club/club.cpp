#include<bits/stdc++.h>
using namespace std;
int t;
void solve(){
	int n;
	long long ans=0;
	vector<int>a,b,c;
	int x[100005];
	int y[100005];
	int z[100005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i]>>z[i];
		if(x[i]>=y[i]&&x[i]>=z[i])a.push_back(i);
		else if(y[i]>=x[i]&&y[i]>=z[i])b.push_back(i);
		else c.push_back(i);
	}
	for(int i=0;i<int(a.size());i++)ans+=x[a[i]];
	for(int i=0;i<int(b.size());i++)ans+=y[b[i]];
	for(int i=0;i<int(c.size());i++)ans+=z[c[i]];
	if(int(a.size())>(n/2)){
		vector<int>v;
		for(int i=0;i<int(a.size());i++)v.push_back(min(x[a[i]]-y[a[i]],x[a[i]]-z[a[i]]));
		sort(v.begin(),v.end());
		for(int i=0;i<int(a.size())-(n/2);i++)ans-=v[i];
	}
	if(int(b.size())>(n/2)){
		vector<int>v;
		for(int i=0;i<int(b.size());i++)v.push_back(min(y[b[i]]-x[b[i]],y[b[i]]-z[b[i]]));
		sort(v.begin(),v.end());
		for(int i=0;i<int(b.size())-(n/2);i++)ans-=v[i];
	}
	if(int(c.size())>(n/2)){
		vector<int>v;
		for(int i=0;i<int(c.size());i++)v.push_back(min(z[c[i]]-y[c[i]],z[c[i]]-x[c[i]]));
		sort(v.begin(),v.end());
		for(int i=0;i<int(c.size())-(n/2);i++)ans-=v[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
