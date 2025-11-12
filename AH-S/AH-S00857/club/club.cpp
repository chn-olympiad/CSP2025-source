#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7,inf=1e18;
int t,n,s1,c[N],s2,s3,b[N],d1,d2,e1[N],e2[N];
struct xyf{
	int o1,o2,o3;
};
xyf a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int o=n/2;
		int f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].o1>>a[i].o2>>a[i].o3;
			if(a[i].o2) f1=0;
			if(a[i].o3) f2=0;
			b[i]=a[i].o1;
		}
		if(f1){
			int ans=0;
			sort(b+1,b+n+1);
			for(int i=o+1;i<=n;i++){
				ans+=b[i];
			}
			cout<<ans<<"\n";
		}
	}
	// I love China , NOI and CCF!
	return 0;
}
