#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
unordered_map<long long,long long> mp;
priority_queue<long long> qmax;
priority_queue<long long,vector<long long>,greater<long long> > qmin; 
long long a[N],s[N];
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	bool f=0;
	long long ans=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mp[a[i]]=i;
		if(a[i]!=1) f=1;
	}
	if(f==0&&k==0){
		cout<<n/2;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			vis[i]=1;
			qmax.push(i);
			qmin.push(i);
		}
	}
	for(long long i=1;i<=n;i++){
		long long x=a[i]^k;
		if(mp[x]==i) continue;
		if(mp[x]) {
			 if(i>=qmin.top()&&i<=qmax.top()){
				continue;
			}
			else if(mp[x]<=qmax.top()&&mp[x]>=qmin.top()) continue;
			else {
				ans++;
				qmin.push(mp[x]);
				qmin.push(i);
				qmax.push(mp[x]);
				qmax.push(i);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
