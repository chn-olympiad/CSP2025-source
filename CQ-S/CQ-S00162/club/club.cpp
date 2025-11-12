#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z,maxn;
}a[N];
int t,n;
signed main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxn=max(max(a[i].x,a[i].y),a[i].z);
			ans+=a[i].maxn;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
