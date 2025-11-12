#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],sum[100010],cnt=0,f[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			sum[i]=a[i];
		}
		else{
			sum[i]=a[i]^sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l<=n-i+1;l++){
			int r=l+i-1;
			if((l==1&&sum[r]==m)||(sum[r]^sum[l-1])==m){
				int x=1;
				for(int j=l;j<=r;j++){
					if(f[j]==1){
						x=0;
						break;
					}
				}
				if(x==1){
					cnt++;
					for(int j=l;j<=r;j++){
							f[j]=1;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
