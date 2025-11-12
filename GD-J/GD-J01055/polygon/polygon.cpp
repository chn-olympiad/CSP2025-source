#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
long long n,a[100006],ans=0;
const long long mod=998244353;
void dfs(long long id,long long sum,long long ma,long long c){
	if(id==n){
		if(c>=3&&sum>2*ma)ans++;
		return;
	}
	dfs(id+1,sum+a[id+1],max(ma,a[id+1]),c+1); 
	dfs(id+1,sum,ma,c);
}
void work1(){
	ans=0;
	dfs(0,0,0,0);
	cout<<ans;
}
long long f(long long l,long long r){
	long long an=1,cnt=1;
	vector<long long> v;
	v.clear(); 
	for(int i=1;i<=r-l;i++){
		v.push_back(i);
	}
	for(int i=l+1;i<=r;i++){
		an*=i;
		for(long long j=0;j<v.size();j++){
			if(v[j]!=-1){
				if(an%v[j]==0){
					an/=v[j];
					v[j]=-1;
					cnt++; 	
				}
			}
		}
		if(cnt==v.size())an%=mod;
	}
	if(l==r)return 1;
	return an%mod;
}
void work2(){
	for(long long i=3;i<=n;i++){
		ans+=f(i,n);
		ans%=mod;
	}
	cout<<ans;
}
int main(){
	op();
	cin>>n;
	long long p=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		p+=(a[i]==1);
	}
	sort(a+1,a+1+n);
	if(p==n)work2();
	else if(n<=20)work1();
	return 0;
}
/*
sum>2*max

*/
