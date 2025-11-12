#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,pos,a[500010],ans=1,as=1,flag=0,dp[500010]={1},maxn;
struct kk{
	int l,r;
};
kk z[5000010];
bool cmp(kk a,kk b){
	return a.l<b.l; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int pos=a[i];
		if(pos==k){
			z[as].l=i,z[as].r=i;
			as++;
		}
		for(int j=i+1;j<=n;j++){
			pos=(a[j]^pos);
			if(pos==k){
				z[as].l=i,z[as].r=j;
				as++;
			}
		}
	}
	sort(z+1,z+as,cmp);
	for(int i=1;i<as;i++){
		for(int j=1;j<i;j++){
			if(z[i].l>z[j].r) dp[i]=max(dp[j]+1,dp[i]);
		}
		maxn=max(dp[i],maxn);
	}
	cout<<maxn+1;
	return 0;
}
// 2 minutes,but.....
