#include<bits/stdc++.h>
const int N=5005,mod=998244353;
using namespace std;
vector<int>v;map<int,int>m;
inline void ins(int x){
	if(m[x]){m[x]++;return;}
	v.push_back(x);m.insert({x,1});
	int i=v.size()-1;
	while(v[i-1]>v[i])swap(v[i],v[i-1]),i--;
}
int n,a[N],ans=0,i,j;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int l,r,md;cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);v.push_back(a[0]+a[1]),m.insert({a[0]+a[1],1});
	for(i=2,n--;i<n;i++){
		l=0,r=v.size();
		while(l+1<r){
			md=(l+r)>>1;
			if(v[md]<=a[i])l=md;
			else r=md;
		}l=v.size();
		while(r<l)ans=(ans+m[v[r++]])%mod;
		vector<int>ve=v;
		for(j=0;j<ve.size();j++)ins(a[i]+ve[j]);
		for(j=0;j<i;j++)ins(a[i]+a[j]);
	}
	l=0,r=v.size();
	while(l+1<r){
		md=(l+r)>>1;
		if(v[md]<=a[n])l=md;
		else r=md;
	}l=v.size();
	while(r<l)ans=(ans+m[v[r++]])%mod;
	if(ans)cout<<ans;
	else cout<<n;
}
