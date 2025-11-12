#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,cnt,ans,pos;
int a[N],sum[N];
struct ly{
	int l,r;
} b[N*20];
bool cmp(ly x,ly y){
	if(x.r==y.r) return x.l>y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				b[++cnt].l=i;
				b[cnt].r=j;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(b[i].l>pos){
			ans++;
			pos=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
