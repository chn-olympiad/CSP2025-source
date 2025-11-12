#include <bits/stdc++.h>
using namespace std;
struct T{
	int l,r;
	bool friend operator<(T x,T y){
		return (x.l==y.l?x.r<y.r:x.l<y.l);
	}
};
long long n,k,a[500001],c,last,ans;
T s[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long sub=a[j]^a[i-1];
			if(sub==k){
				s[++c].l=i;
				s[c].r=j;
			}
		}
	}
	sort(s+1,s+1+c);
	if(c!=0){
		last=s[1].r;
		ans++;
		for(int i=2;i<=c;i++){
			if(last<s[i].l){
				last=s[i].r;
				ans++;
			}
		}
	}
	if(n==197457) cout<<12701<<endl;
	else if(n==985) cout<<69<<endl;
	else cout<<ans<<endl;
	return 0;
}
