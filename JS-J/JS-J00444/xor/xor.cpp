#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,k,a[N],sum,ans;
struct node {
	int x,y;
}b[N];
bool vis[N];
bool cmp(node a,node b) {
	if(a.y==b.y) return a.x>b.x;
	return a.y<b.y;
}
void f() {
	for(int i=1;i<=sum;i++) {
		if(b[i].y!=b[i-1].y) {
			bool flag = 0;
			for(int j=b[i].x;j<=b[i].y;j++) {
				if(vis[j]) {
					flag=1;
					break;
				}
			}
			if(!flag){
				ans++;
				for(int j=b[i].x;j<=b[i].y;j++) {
					vis[j]=1;
				}
			}
		}
	}
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
 	cin>>n>>k;
 	for(int l,i=1;i<=n;i++) {
		cin>>l;
		a[i]=a[i-1]^l;
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			if((a[j]^a[i-1])==k) {
				b[++sum].x=i;
				b[sum].y=j;
				break;
			}
		}
	}
	sort(b+1,b+sum+1,cmp);
	f();
	cout<<ans;
	cout<<endl;
	return 0;
}
