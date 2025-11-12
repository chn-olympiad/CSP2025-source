#include <bits/stdc++.h>
using namespace std;
int n,k,f[500010],s[500010];
int cnt,ans;
struct qj{
	int l;
	int r;
}q[500010];
bool cmp(qj x,qj y){
	return x.r<y.r;
}
int xo(int a,int b){
	int d=int(a^b);
	return d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
    	cin >> f[i];
    	s[i]=xo(f[i],s[i-1]);
    	for (int j=0;j<=i-1;j++){
    		if (int(s[i]^s[j])==k){
    			cnt++;
    			q[cnt].l=j+1;
    			q[cnt].r=i;
    		}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int t=q[1].r;
	int ii=2;
	ans=1;
	while(ii<=cnt){
		while(q[ii].l<=t&&ii<=cnt)ii++;
		if (ii>cnt)break;
		if (q[ii].l>t){
			t=q[ii].r;
			ans++;
		}
	}
	cout << ans;
    return 0;
}
