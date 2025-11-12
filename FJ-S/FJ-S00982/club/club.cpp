#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int T,n,a[N],b[N],c[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--){
			ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
