#include<bits/stdc++.h>
using namespace std;
int a[6000],sum[6000],p[6000];
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(p,0,sizeof(p));
	bool flag=0;
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=(a[i]^a[i-1])+sum[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				if(p[i]==1)continue;
				if(a[i]==k)ans++;
				p[i]=1;
			}else{
				for(int ij=i;ij<=j;ij++){
					if(p[i]==1){
						flag=1;
						break;
					}
				}
				if(flag==1)continue;
				int zs=sum[j]-sum[i-1];
				if(zs==k)ans++;
				for(int ij=i;ij<=j;ij++)p[ij]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
//R
