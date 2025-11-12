#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],l[N],r[N],sum[N];
struct sb{
	int l;
	int r;
}c[N];
bool cmp(sb x,sb y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int e=sum[j]^sum[i-1];
			if(e==k){
				c[++cnt].l=i;
				c[cnt].r=j;
			}
		}
	}
	sort(c+1,c+1+cnt,cmp);
	int ans=0;
	int t=0;
	for(int i=1;i<=cnt;i++){
		if(c[i].l>t){
			t=c[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
