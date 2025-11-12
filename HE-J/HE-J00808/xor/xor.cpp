#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[500100];
struct ppp{
	int l,r;
}e[5001000];
bool cmp(ppp x,ppp y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=1;
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=i;j<=n;j++){
			p=p^a[j];
			if(p==k){
				e[c].l=i;
				e[c].r=j;
				c++;
			}
		}
	}
	sort(e+1,e+1+c,cmp);
	int p=1;
	for(int i=1;i<=c;i++){
		if(e[i].l>=p){
			p=e[i].r+1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
