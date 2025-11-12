#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,Mod=998244353;
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%Mod;
		a=a*a%Mod;
		b=b>>1;
	}
	return ans;
}
int n,q,ans; 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	cout<<ksm(2,q);
}
