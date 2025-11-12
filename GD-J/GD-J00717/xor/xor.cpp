#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long  s[N],q[N],mp[500],yu[500];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1; i<=n; i++) {
		cin>>s[i];
		q[i] = q[i-1]^s[i];
	}

	int maxn=0;
	int ans=0;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=i; j++) {
			if((q[j-1]^q[i])==k&&j-1>=0) {

				bool p=1;
				for(int k = i;k<=j;k++){
					if(mp[k]==1) p=0;
				}
				if(p) {
					ans++;
					for(int k = i;k<=j;k++)
					mp[k]=1;
				
				}
				
			}

		}
	}

	cout<<ans;
}
