#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define VLL vector<long long>
const int N=114514;
ll n,m,ans=0;
string c1,c2,c,s;
string s1[N],s2[N];
int main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) cin>>s1[i]>>s2[i];
	for(int i=1; i<=m; i++) {
		cin>>c1>>c2;

		for(int j=0; j<c1.size(); j++) {
			s=c1;
			for(int i=1; i<=n; i++) {
				bool fl=1;
				for(int k=0; k<s1[i].size(); k++) {
					if(s[j]!=s1[i][k]) {
						fl=0;
						break;
					}
				}
//				if(fl) {
//					for(int k=0; k<s1[i].size(); k++) {
//					
//					}
//				}
			}
			if(s==c2) ans++;
		}
//		cout<<ans;
		cout<<0;
	}
	return 0;
}

