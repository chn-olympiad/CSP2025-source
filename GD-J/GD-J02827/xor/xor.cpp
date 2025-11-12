#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k,a[N],sum[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)flag=0;
		sum[i]=sum[i-1]^a[i];
	}

	int lim=1,minj=1e9,ans=0;
	while(lim<=n){
		minj=1e9;
		for(int l=lim;l<=min(minj,n);l++){
			for(int r=l;r<=n;r++){
				if((sum[r]^sum[l-1])==k){
					minj=min(minj,r);
					break;
				}
			} 
		}
		//找到新区间了，要更新lim 
		if(minj!=1e9){
			ans++;
			lim=minj+1;
		}
		//找不到新区间，结束循环 
		else break;
	}
	cout<<ans<<'\n';
	return 0; 
}
