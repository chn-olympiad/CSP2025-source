#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],p,mn=2147483647;
unordered_map<long long,unordered_map<long long,long long>> mp;
unordered_map<long long,long long> d;
int er(long long l,long long r,long long f,long long q){
	if(l>=r) return l;
	int mid=(l+r)/2;
	if(mp[f][mid]>q) return er(l,mid,f,q);
	return er(mid+1,r,f,q);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	d[0]++;
	mp[0][1]=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=a[i]^s[i-1];
		d[s[i]]++;
		mp[s[i]][d[s[i]]]=i;
	}
	for(long long i=0;i<=n;i++){
		if(i==1+mn){
			p++;
			mn=2147483647;
		}
		if(d[k^s[i]]&&mp[k^s[i]][d[k^s[i]]]>i) mn=min(mp[k^s[i]][er(1,d[k^s[i]],k^s[i],i)]-1,mn);
	}
	printf("%lld",p);
	return 0;
}
