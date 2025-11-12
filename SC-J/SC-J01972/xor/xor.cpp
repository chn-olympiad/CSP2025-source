#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,k;
int arr[N];
struct p{int l,r;}jl[N>>1];
int qzh[N],idx=0;
bool cmp(p f,p s){
	return (f.r-f.l)<(s.r-s.l);
}
bool mp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1,f2=1,f3=1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=1)f=0;
		if(arr[i]>1)f2=0;
		if(arr[i]>255)f3=0;
	}
	if(f&&k==0){cout<<n/2;return 0;}//特殊性质A:对于所有1≤i≤n,均有ai=1。
	if(f2&&k<=1){//特殊性质B:对于所有1≤i≤n,均有0<=ai≤1。
		int l=0,y=0;
		for(int i=1;i<=n;i++)(arr[i]==1)? y++:l++;
		if(k==0)cout<<l+y/2;
		else cout<<y;return 0;
	}
	//暴力
	for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]^arr[i];
	for(int i=1;i<=n;i++)if(arr[i]==k)jl[++idx].l=i,jl[idx].r=i;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if((qzh[i-1]^qzh[j])==k)jl[++idx].l=i,jl[idx].r=j;
	sort(jl+1,jl+1+idx,cmp);
	long long ans=0;
	for(int i=1;i<=idx;i++){
		bool flag=1;
		for(int j=jl[i].l;j<=jl[i].r;j++)if(mp[j]==1)flag=0;
		if(flag){
			ans++;
			for(int k=jl[i].l;k<=jl[i].r;k++)mp[k]=1;
		}
	}
	cout<<ans;
	return 0;
}
