#include<bits/stdc++.h>
using namespace std;
int a[20],b[20],c[20];
long long x=1;
int mod=998224353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	if(n<=18){
		for(int i=1;i<=n;++i){
			x*=i;
		}
		for(int i=1;i<=n;++i){
			a[i]=i;
		}
		long long fail,ans=0;
		
		for(long long i=1;i<=x;++i){
			fail=0;
			for(int j=1;j<=n;++j){
				c[j]=b[a[j]];
			}
			for(int j=1;j<=n;++j){
				if(s[j-1]=='0'||fail>=c[j]){
					fail++;
				}
			}
			if(n-fail>=m)ans++;
			next_permutation(a+1,a+n+1);
			ans=ans%mod;
		}
		cout<<ans<<endl; 		
	} 
	return 0;
}
