#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],bcount=0;
bool c[5005];
int pd(int t){
	long long ans=0;
	for(int i=1;i<=t;i++){
		ans+=a[b[i]];
		if(ans>a[b[t]]*2){
		return 0;
	}
	}
	return 1;
}
void dfs(int m,int k){
	if(k==m+1){
		if(pd(m)==0){
			bcount++;
			bcount=bcount%998244353;
		}
		return;
	}
	
	for(int i=1;i<=n-(m-k);i++){
		if(c[i]==0&&i>b[k-1]){
			b[k]=i;
			if(k==m){
				if(pd(m)==1){
					break;
				}
			}
			c[i]=1;
			dfs(m,k+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,1);
	}
	cout<<bcount;
}
