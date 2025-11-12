#include<bits/stdc++.h>
using namespace std;
int a[1000005],sum[1000005];
int n,k;
int xormy(int x,int y){
	int k1[25],k2[25];
	memset(k1,0,sizeof k1);
	memset(k2,0,sizeof k2);
	int n1=0,n2=0;
	while(x){
		k1[++n1]=x%2;
		x/=2;
	}
	while(y){
		k2[++n2]=y%2;
		y/=2;
	}
	int k[25],n3=max(n1,n2);
	for(int i=1;i<=max(n1,n2);i++){
		if(k1[i]!=k2[i]) k[i]=1;
		else k[i]=0;
	}
	int bit=1;
	int ans=0;
	for(int i=1;i<=n3;i++){
		ans+=k[i]*bit;
		bit*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=xormy(sum[i-1],a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int res=a[i];
			for(int l=i+1;l<=j;l++){
				res=xormy(res,a[l]);
			}
			if(res==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
