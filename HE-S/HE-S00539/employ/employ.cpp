#include <bits/stdc++.h>
#define md 998244353
#define ll long long
using namespace std;
const int MN=1501;
int n,m,cnt,cnt1;
char c[MN];
int a[MN];
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,c+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}sort(a+1,a+1+n);
	cnt1=n-cnt;
	for(int i=m;i<=cnt1;i++){
		ll res=1;
		for(int j=0;j<i;j++){
			res=res*(cnt1-j)%md;
		}ans+=res;
	}printf("%lld",ans);
	return 0;
}
