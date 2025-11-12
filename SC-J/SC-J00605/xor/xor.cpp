#include<bits/stdc++.h>
using namespace std;
long long n,Q,a[500005],xor_[500005],ans,x=1,y=1,cnt,f[500005],max_;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)cin>>a[i],xor_[i]=xor_[i-1]^a[i],max_=max(max_,a[i]);	
	for(int i=1;i<=n;i++){if(a[i]==Q)f[++cnt]=i;}
	f[cnt+1]=n+1;
	for(int i=1;i<=cnt+1;i++){
		x=y=f[i-1]+1;
		for(int j=x;j<=f[i]-1;j++){
			for(int k=y;k<=j;k++){
				if((xor_[j]^xor_[k-1])==Q){ans++,x=y=j+1;break;}
			}
		}
	}
	cout<<ans+cnt;
	return 0;
}