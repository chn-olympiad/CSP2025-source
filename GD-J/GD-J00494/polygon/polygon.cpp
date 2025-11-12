#include<bits/stdc++.h>
using namespace std;
//struct node{
//	long long bh;
//	long long maxn;
//	long long sum;
//	long long gs;
//};
vector<long long> a(5100),s(5100);
map<pair<pair<long long,long long>,pair<long long,long long> >,long long> m;
long long f(long long bh,long long maxn,long long sum,long long gs){
	if(bh==0){
		return maxn<sum;
	}
	if(gs+bh<3){
		return 0;
	}
	if(sum>maxn&&gs>=3){
		int ans=1;
		while(bh>1){
			bh-=1;
			ans=ans<<1;
			ans%=998244353;
		}
		return (ans<<bh)%998244353;
	}
	if(sum+s[bh]<=maxn){
		return 0;
	}
	pair<pair<long long,long long>,pair<long long,long long> > new_node;
	new_node.first.first=bh;
	new_node.first.second=maxn;
	new_node.second.first=sum;
	new_node.second.second=min(gs,(long long)3);
	if(m[new_node]>0){
		return m[new_node]-1;
	}
	long long ans=f(bh-1,maxn,sum,gs)+f(bh-1,maxn,sum+a[bh],gs+1);
	ans%=998244353;
	m[new_node]=ans+1;
	return ans;
}
int main(){
	ifstream in("polygon.in");
	ofstream out("polygon.out");
	long long n;
	in>>n;
	for(long long i=1;i<=n;i++){
		in>>a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=3;i<=n;i++){
		ans+=f(i-1,a[i]*2,a[i],1);
		ans%=998244353;
	}
	out<<ans;
	return 0;
}
