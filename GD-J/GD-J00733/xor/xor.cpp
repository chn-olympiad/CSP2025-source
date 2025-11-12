#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; s[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i]; s[i]=s[i-1]^a[i];
	}
	set<int> st; int ans=0; st.insert(s[0]);
	for(int i=1;i<=n;i++) {
		if(st.count(k^s[i])) {
			ans++; st.clear();
		}
		st.insert(s[i]);
	}
	cout<<ans;
	return 0;
}
