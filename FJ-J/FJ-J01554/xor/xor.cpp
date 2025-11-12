#include<bits/stdc++.h>
using namespace std;
int n,k,mi=1e9,ma,ans,a[500005],b[500005];
struct node{
	int l,r;
}c[500005];
bool cmp(node a,node b){
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}
void B(){
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				ans+=cnt/2;
				cnt=0;
			}
			else{
				cnt++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout<<ans;
}
void O(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((b[r]^b[l-1])==k){
				c[++cnt].l=l;
				c[cnt].r=r;
			}
		}
	}
	sort(c+1,c+1+cnt,cmp);
	int r=0;
	for(int i=1;i<=cnt;i++){
		if(c[i].l>r){
			r=c[i].r;
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
	}
	if(mi==1 && ma==1 && k==0) cout<<n/2; 
	else if(mi==0 && ma==1) B();
	else O();
	return 0;
}
