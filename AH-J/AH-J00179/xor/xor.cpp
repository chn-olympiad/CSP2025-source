#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],dp[500005];
struct node{
	int l,r;
}c[500005];
int cmp(node x,node y){
	if(x.l!=y.l)
		return x.l<y.l;
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,m=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)
			b[i]=a[i];
		else
			b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				ans++,c[ans].l=i,c[ans].r=j,m=max(m,j);
				break;
			}
		}
	}
	sort(c+1,c+1+ans,cmp);
	int mr=-1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ans;j++){
			if(c[j].r<=i&&c[j].l>mr){
				dp[m]++,mr=c[j].r;
			}
		}
	}
	cout<<dp[m];
	return 0;
}
