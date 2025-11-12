#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define LL long long
LL n;
vector<LL> A;
LL ans=0;
void dfs(LL x,LL len,LL num,LL maxl,bool flag){
	if(num>=3 && len>2*maxl && flag){
		
		//cout<<x<<" "<<len<<" "<<num<<" "<<maxl<<"\n";
		
		ans++;
		ans%=MOD; 
	}
	if(x==n)return;
	dfs(x+1,len+A[x],num+1,A[x],true);
	dfs(x+1,len,num,maxl,false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=300&&n<=5000){
		ans=0;
		for(LL i=3;i<=n;i++){
			LL tmp=1;
			for(LL j=n;j>=n-i;j--){
				tmp*=j;
				tmp%=MOD;
			}
			for(LL j=1;j<=i;j++){
				tmp/=j;
				tmp%=MOD;
			}
			ans+=tmp;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	} 
	A=vector<LL>(n);
	for(LL i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	dfs(0,0,0,0,false);
	cout<<ans;
	return 0;
} 
