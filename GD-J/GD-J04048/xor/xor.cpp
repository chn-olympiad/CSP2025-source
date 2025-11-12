#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
ll a[500010],p[500010];
struct v{
	ll l,r;
};
vector<v> q;
bool cmp(v a,v b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
		p[i]=p[i-1]^a[i];
	}
	if(f){
		cout<<n/2;
	}else if(n<=1e5){
		//p[r]^p[l-1]=a[l]^a[l+1]^a[l+2]^...^a[r];
		//l=1,2,3,4,...,n;
		//r=1,2,3,4,...,n;
		for(ll l=1;l<=n;l++){
			for(ll r=l;r<=n;r++){
				if((p[r]^p[l-1])==k){
					q.push_back({l,r});
					//cout<<l<<' '<<r<<'\n';
				}
			}
		}
		sort(q.begin(),q.end(),cmp);
		ll eid=-1,ans=0;
		for(auto i:q){
			if(i.l>eid){
				//cout<<i.l<<' '<<i.r<<'\n';
				ans++;
				eid=i.r;
			}
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
