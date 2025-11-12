#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005];
struct node{
	int st,ed;
}b[500005];
bool cmp(node x,node y){
	if(x.ed==y.ed)return x.st>y.st;
	return x.ed<=y.ed;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int m=0;
	for(int l=1 ;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sum[r]^sum[l-1])==k){
				b[++m].st=l;
				b[m].ed=r;
				break;
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	int ans=1,r=b[1].ed;
	for(int i=2;i<=m;i++){
		if(b[i].st>r){
			r=b[i].ed;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
