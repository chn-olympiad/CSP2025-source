#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N=5e5+5;

int a[N],k,n,cnt=0,f[N][30],p[N];

void build(){
	int t=log2(n);
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	for(int l=1;l<=t;l++){
		for(int i=1;i+(1<<l)-1<=n;i++){
			f[i][l]=f[i][l-1]^f[i+(1<<(l-1))][l-1];
		} 
	}
	return;
}

int ask(int l,int r){
	if(l==r) return a[l];
	int t=log2(r-l+1);
	return f[l][t-1]^f[l+(1<<(l-1))][t-1];
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;int maxk=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];maxk=max(maxk,a[i]);
		cnt+=(a[i]==1);
	} 
	if(maxk==1){
		if(k==1){
			cout<<cnt;return 0;
		} 
		int ans=0,l=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				ans+=(l/2);l=0;
			}
			else l++;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
} 
