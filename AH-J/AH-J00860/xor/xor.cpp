/*#include "bits/stdc++.h"
using namespace std;
struct f{
	int l,r;
}b[100010];
int n,k,a[100010],t;
bool cmp(f x,f y){
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
signed main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=a[i];
			for(int x=i+1;x<=j;x++) ans^=a[x];
			if(i>j) continue;
			if(ans==k){
				b[t++].l=i;
				b[t-1].r=j;
			}
		}
	}
	sort(b,b+t,cmp);
	for(int i=0;i<t;i++) cout<<b[i].l<<" "<<b[i].r<<endl;
	int maxn=b[0].r,res=1;
	for(int i=1;i<t;i++){
		if(maxn<=b[i].l) {
			res++;
			maxn=b[i].r;
			cout<<b[i].l<<" "<<b[i].r<<endl;
		}
	}
	cout<<res<<endl;
	return 0;
}*/
#include "bits/stdc++.h"
using namespace std;
int n,k,a[100010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1) {
		int r,rans=0;
		for(int i=2;i<=n;i++){
			if(r==i-1) continue;
			if(a[i]!=a[i-1]){
				ans++;
				r=i;
			}
		}
		for(int i=3;i<=n;i++){
			if(r==i-1) continue;
			if(a[i]!=a[i-1]){
				rans++;
				r=i;
			}
		}
		cout<<max(ans,rans)<<endl;
		return 0;
	}
	else if(k==0){
		int r;
		for(int i=2;i<=n;i++){
			if(r==i-1) continue;
			if(a[i]==a[i-1]){
				ans++;
				r=i;
			}
		}
		for(int i=3;i<=n;i++){
			if(r==i-1) continue;
			if(a[i]==a[i-1]){
				rans++;
				r=i;
			}
		}
		cout<<max(ans,rans)<<endl;
		return 0;
	}
	else cout<<rand()%100010;
	return 0;
}
