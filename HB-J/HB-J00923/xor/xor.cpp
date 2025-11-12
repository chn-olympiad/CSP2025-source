#include<bits/stdc++.h>
using namespace std;
struct node{
	int left,right;
};
node x[500005];
bool cmp(node a,node b){
	return a.right<b.right;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],xn=0;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			int ans=a[l];
			for(int i=l+1;i<=r;i++){
				ans=ans^a[i];
			}
			if(ans==k){
				x[xn++].left=l;
				x[xn-1].right=r;
			}
		}
	}
	if(xn==0){
		cout<<0;
		return 0;
	}
	sort(x,x+xn,cmp);
	int now=x[0].right;
	int ans=1;
	for(int i=1;i<xn;i++){
		if(x[i].left>now){
			now=x[i].right;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
