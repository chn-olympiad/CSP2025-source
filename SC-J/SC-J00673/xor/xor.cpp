#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int N=5e5+10;
int a[N];
set<int>st;//va
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	int ans=0;
	st.insert(0);
	for(int i=1;i<=n;i++){
		if(st.count(a[i]^k)){
			st.clear();
			ans++;
		}
		st.insert(a[i]);
	}
	cout<<ans;
	return 0;
}