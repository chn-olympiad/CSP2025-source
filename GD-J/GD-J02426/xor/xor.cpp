#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[256],ans;
map<int,int> p;
map<int,int>::iterator it;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]=a[i]^a[i-1]^k;
		p[a[i]]++;
	}
	
	for(it=p.begin();it!=p.end();it++) {
		ans=max(ans,it->second);
	}
	
	
	cout<<ans;
	return 0;
}
