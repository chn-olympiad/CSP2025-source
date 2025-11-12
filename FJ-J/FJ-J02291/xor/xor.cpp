#include<bits/stdc++.h>
using namespace std;
int  a[200005],sum[200005];
long long ans=0;
struct node{
	int l,r;
}b[200005];
bool cmp(node a,node b){
	if(a.r!=b.r) return a.r<b.r;
	return a.l>b.l;
}
int n,k,p=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int  i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sum[l-1]^sum[r])==k){
				b[p].l=l;
				b[p].r=r;
				p++;	
			}
		}
	}
	int minr=0;
	sort(b+1,b+1+p,cmp);
	for(int i=1;i<=p;i++){
		if(b[i].l>minr){
			minr=b[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
