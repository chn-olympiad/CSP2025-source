//GZ-S00433 遵义市第四中学 邓嘉瑶
#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
string s;
int n,m,c[505];
long long ans=1,num=1;
int main() {
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	if(m==1) {
		for(int i=1; i<n; i++) {
			num*=i%Mod;
		}
		long long ans1=0,t=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='0') {
				t++;
			} else {
				for(int i=1; i<=n; i++) {
					if(c[i]>t) {
						ans1+=num%Mod;
					}
				}
				t=0;
			}
		}
		if(ans1>0) {
			cout<<ans1%Mod;
			return 0;
		}
	}
	bool pd=1;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='0') {
			pd=0;
		}
	}
	if(pd) {
		for(int i=1; i<=n; i++) {
			ans*=i%Mod;
		}
	}
	cout<<ans%Mod;
	return 0;
}
