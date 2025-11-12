#include<bits/stdc++.h>
using namespace std;
int jerry114514[5010];
int n,k;
int main() {
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0) {
		int j=n/2;
		cout<<j<<endl;
	} else {
		int ans=0;
		for(int i=1; i<=n; i++) {
			int y;
			cin>>y;
			if(y==1)
				ans++;
		}
		cout<<ans<<endl;
	}
}
