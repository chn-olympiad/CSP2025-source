#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,ans=0;
long long cnt[5005],t[5005];
set<long long> a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long tmp;
		cin>>tmp;
		a.insert(tmp);
		cnt[tmp]++;
		if(cnt[tmp]>=3){
		    ans+=cnt[tmp]-2;
		}
	}
	cout<<ans%MOD;
	return 0;
}
