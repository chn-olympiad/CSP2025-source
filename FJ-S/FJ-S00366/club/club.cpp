#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=100100;
int t,n,a[N],b[N],c[N];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=n-n/2+1;i--){
		ans+=a[i];
	}printf("%d\n",ans);
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t;--t){
		solve();
	}
	rt 0;
}                                         
