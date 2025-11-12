#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005],c[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ans=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=max(a[i],max(b[i],c[i]));
		}
	}
	cout<<ans;
	return 0;
} 
