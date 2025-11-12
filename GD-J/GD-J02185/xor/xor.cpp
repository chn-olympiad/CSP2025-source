#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
int n,r,ans;
long long k,a[500007],t;
vector<pair<int,int> >vt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]=a[i-1] xor a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			t=a[i-1]^a[j];
			if(t==k) vt.push_back({i,j});
		}
	}
	sort(vt.begin(),vt.end());
	for(auto i:vt){
		if(i.fi<=r) r=min(r,i.sc);
		else{
			++ans;
			r=i.sc;
		}
	}
	cout<<ans;
	return 0;
}
