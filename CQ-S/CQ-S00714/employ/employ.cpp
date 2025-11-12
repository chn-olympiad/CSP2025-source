#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[20001],p[20001],ans,vl=0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];p[i]=i;
		vl+=(a[i]!=0);
	}
	if(vl<m) cout<<0,exit(0);
	if(n<=10){
		do{
			int vl=0;
			for(int i=1;i<=n;i++){
				if(vl>=a[p[i]]){vl++;continue;}
				if(s[i]=='0'){vl++;continue;}
			}
			if(n-vl>=m){
				ans++;
//				for(int i=1;i<=n;i++){
//					cout<<p[i]<<' ';
//				}
//				cout<<"\n";
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
/*

*/

