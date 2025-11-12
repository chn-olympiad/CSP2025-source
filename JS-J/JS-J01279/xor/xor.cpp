#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005],c=0,t=0;;
vector<pair<int,int> >v;
map<int,int>m;
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1];
		b[i]^=a[i];
	}
	for(int i=1;i<=n;i++){
		int x=b[i];
		m[b[i-1]]=i;
		if(m[x^k]){
			v.push_back({m[x^k],i});
		}
	}
	
	sort(v.begin(),v.end(),cmp);
	c=1,t=v[0].second;
	for(int i=1;i<v.size();i++){
		if(v[i].first>t){
			c++;
			t=v[i].second;
		}
	}
	cout<<c;
	return 0;
}
