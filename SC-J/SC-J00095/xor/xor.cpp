#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("xcor.in","r",stdin);
	freopen("xcor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,x,p,ans=0;
	cin>>n>>p;
	vector<ll>s;
	for(int i=1;i<=n;i++){
		cin>>x;
		s.push_back(x);
	}for(int i=0;i<n;i++){
		ll t=s[i],f=i,m=i,o=0;
		while(f<=m&&m<n){
			if(t==p){
				f=m+1;
				m++;
				o++;
				if(m==n)break;
				p=s[m];
				continue;
			}else{
				m++;
				p^=s[m];
			}
		}ans=max(ans,o);
	}cout<<ans;
	return 0;
}