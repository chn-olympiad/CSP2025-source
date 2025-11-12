#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int Aa[500005],ri[500005],rr,sum[500005]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(ri,0x3f,sizeof(ri));
	for(int i=1;i<=n;i++){
		cin>>Aa[i];
		sum[i]=sum[i-1]^Aa[i];
//		cout<<sum[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ri[i]=j;
				break;
			}
		}
//		cout<<ri[i]<<" ";
	}
//	cout<<"\n";
	int l=1,rr;
	while(l<=n){
		rr=ri[l];
//		cout<<l<<" "<<rr<<endl;
		for(int i=l+1;i<rr&&i<=n;i++){
			if(ri[i]<rr){
				if(l==1)ans--;
				rr=ri[i];
				l=rr+1;
			}
		}
		l=rr+1;
		ans++;
	}
	cout<<ans;
	return 0;
}