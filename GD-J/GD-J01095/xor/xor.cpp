#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,xb,k,s[N],ans,zd;
struct 
struct f{
	int l;
	int r;
}a[N*N];
bool cmp(f x,f y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		int w=s[i];
		if(w==k){
			xb++;
			a[xb].l=i;
			a[xb].r=i;
		}
		for(int j=i+1;j<=n;j++){
			w=(w^s[j]);
			if(w==k){
				xb++;
				a[xb].l=i;
				a[xb].r=j;
			}
		}
	}
	sort(a+1,a+1+xb,cmp);
	for(int i=1;i<=xb;i++){
		if(a[i].l>zd){
			zd=max(zd,a[i].r);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
