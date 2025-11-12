#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],xs[N],n,k,cnt;
struct node{
	int l, r;
}ok[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],xs[i]=xs[i-1]^a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((xs[j]^xs[i-1])==k) ok[++cnt]={i,j};
	sort(ok+1,ok+cnt+1,cmp);
	int pre=1,ans=1;
	for(int i=2;i<=cnt;i++)
		if(ok[i].l>ok[pre].r) pre=i,ans++;
	cout<<ans;
	return 0;
}
