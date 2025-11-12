#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],dp[N],maxx[1<<22],b[N];
long long ans;
int main(){
//	for(int i(1);i<=6;++i){
//		cout<<"fc xor"+to_string(i)<<".out xor"<<to_string(i)<<".ans\n";
//	}
//	return 0; 
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>k;
    for(int i(1);i<=n;++i)cin>>a[i],b[i]=b[i-1]^a[i];
    for(int i(0);i<(1<<22);++i)maxx[i]=-1;
    for(int i(1);i<=n;++i){
    	int ans=-1,yh=0;
    	maxx[b[i-1]]=max(maxx[b[i-1]],dp[i-1]);
		dp[i]=max(dp[i-1],maxx[b[i]^k]+1);
		
	}
	cout<<dp[n];
    return 0;
}
