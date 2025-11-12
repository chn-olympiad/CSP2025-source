#include <bits/stdc++.h>
#define int long long
using namespace std;
int const g=998244353;
int n,a[5010],b[1010],ans=0;
int f(int l,int max,int cnt,int p){
	if(cnt!=0&&cnt>max*2&&p==0){
		return f(l,max,cnt,1)+1;
	}
	if(l>n) return 0;
	return ((f(l+1,a[l],cnt+a[l],0)%g)+(f(l+1,max,cnt,p)%g))%g;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << f(1,0,0,0) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
