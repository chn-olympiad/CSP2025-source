#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
const int mod=998244353;
int n,A[5004];
ll B[5004],sum;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	REP(z,1,n)cin>>A[z];
	sort(A+1,A+1+n);
	B[0]=1;
	REP(z,1,n){
		REP(i,A[z]+1,5001)(sum+=B[i])%=mod;
		for(int i=5001;i>=0;i--){
			if(i+A[z]>5000)(B[5001]+=B[i])%=mod;
			else (B[i+A[z]]+=B[i])%=mod;
		}
	}
	cout<<sum;
	return 0;
}