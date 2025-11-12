#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100100;
struct stu{
	int x;int y;int z;
}a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,ans=0;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			ans+=max(a[i].x,max(a[i].y,a[i].z));
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
