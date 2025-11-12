#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,minn=INT_MAX,maxn=INT_MIN,sum0=0,sum1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
		if(a[i]==0) sum0++;
		if(a[i]==1) sum1++;
	}
	if(maxn==1&&minn==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(maxn==1&&minn==0){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					sum0++;
					a[i+1]=0;
				}
			}
			cout<<sum0;
		}else cout<<sum1;
		return 0;
	}
	return 0;
}
