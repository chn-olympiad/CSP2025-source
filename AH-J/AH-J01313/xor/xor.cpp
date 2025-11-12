#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct node{
	int l,r;
};
node x[10000005];
int n;
long long k,cnt;
bool cmp(node xx,node yy){
	if(xx.r==yy.r){
		if(xx.r-xx.l+1==yy.r-yy.l+1){
			return xx.l<yy.l;
		}
		return xx.r-xx.l+1<yy.r-yy.l+1;
	}
	return xx.r<yy.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		long long sum = a[i];
		if(sum == k){
			x[++cnt].l = i;
			x[cnt].r = i;
		}
		for(int j = i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				x[++cnt].l = i;
				x[cnt].r = j;
			}
		}
	}
	sort(x+1,x+cnt+1,cmp);
	//for(int i = 1;i<=cnt;i++){
	//	cout << x[i].l<<" "<<x[i].r<<endl;
	//}
	int st = x[1].l,ed = x[1].r;
	long long ans = 1;
	for(int i = 2;i<=cnt;i++){
		if(x[i].l>ed||x[i].r<st){
			st = x[i].l;
			ed = x[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
