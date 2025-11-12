#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct node{
	int l,r;
}g[500005];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x,cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x=a[i];
			for(int q=i+1;q<=j;q++){
				x=x^a[q];
			}
			if(x==k){
				g[++cnt].l=i;
				g[cnt].r=j;
			}
		}
	}
	sort(g+1,g+1+cnt,cmp);
	if(cnt==0){
		cout<<0;
		return 0;
	}
	int ed=g[1].r,ans=1;
	for(int i=1;i<=cnt;i++){
		if(g[i].l>ed){
			ans++;
			ed=g[i].r;
		}
	}
	cout<<ans;
	return 0;
}
