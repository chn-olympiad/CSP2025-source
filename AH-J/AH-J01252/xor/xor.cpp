#include<bits/stdc++.h>
using namespace std;
int sum[500005],d[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a,maxn=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a;
        sum[i]=sum[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j>n){
				break;
			}
			int s=sum[j+i-1]^sum[i-1];
			d[j+i-1]=max(d[j+i-1],d[i+j-2]);
			if(s==k){
				d[j+i-1]=max(d[j+i-1],d[i-1]+1);
			}
			maxn=max(maxn,d[j+i-1]);
		}
		maxn=max(maxn,d[n]);
	}
	cout<<maxn-1;
	return 0;
}
