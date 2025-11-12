#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,k,maxn=0,minn=1e18,sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	if(minn==maxn&&maxn==1&&k==0){
		cout<<n/2;
	}else if(minn>=0&&maxn<=1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					sum++;
				}
			}
			cout<<sum;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}else if(a[i]==1&&a[i+1]==1){
					sum++,i++;
				}
			}
			cout<<sum;
		}
	}
	return 0; 
}