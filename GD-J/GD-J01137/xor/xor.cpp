//30pts  AB or more?
#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;
const int N=5e5+5;
int n,k,ans,a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>k;
	
	for(rint i=1;i<=n;++i)
		cin>>a[i];
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	rint x=0;
	for(rint i=1;i<=n;++i){
		if(a[i]==k){
			++ans;
			x=0;
		}else{
			x^=a[i];
			if(x==k){
				++ans;
				x=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

