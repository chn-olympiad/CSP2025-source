#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}d[2000010];
int n,N,k,fl1,fl0,cnt1,cnt0,co1,a[500010],xo[500010];
bool cmp(const node &x,const node &y){
	if(x.r!=y.r) return x.r<y.r;
	return x.l>y.l; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=1) fl1=1;
		if(x!=1&&x!=0) fl0=1;
		a[i]=x;
		xo[i]=xo[i-1]^x;
		if(x==1) cnt1++;
		if(x==0) cnt0++;
		if(x==1) co1++;
		else{
			cnt0+=co1/2;
			co1=0;
		}
	}
	if(fl1==0){
		cout<<n/2;
		return 0;
	}
	if(fl0==0){
		if(k==1) cout<<cnt1;
		if(k==0) cout<<cnt0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((xo[j]^xo[i-1])==k){
				d[++N].l=i;
				d[N].r=j;
			}	
		}
	}
	sort(d+1,d+1+N,cmp);
	if(N==0){
		cout<<0;
		return 0;
	}
	long long ans=1;
	int nowright=d[1].r;
	for(int i=2;i<=N;i++){
		if(d[i].l>nowright){
			ans++;
			nowright=d[i].r;
		}
	}
	cout<<ans;
	return 0;
}
