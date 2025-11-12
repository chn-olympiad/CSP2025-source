#include<bits/stdc++.h>
using namespace std;
int n,k,sum,ans;
int a[500005];
int s[500005];
struct sz{
	int l;
	int r;
};
sz x[500005];
bool tmp(sz a,sz b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) s[i]=a[i];
		else s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int q;
			if(i==1) q=s[j];
			else q=s[i-1]^s[j];
			if(q==k){
				sum++;
				x[sum].l=i;
				x[sum].r=j;
			} 
		}
	}
	sort(x+1,x+1+sum,tmp);
	int e=x[1].r;
	ans++;
	for(int i=2;i<=sum;i++){
		if(e<x[i].l){
			e=x[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
