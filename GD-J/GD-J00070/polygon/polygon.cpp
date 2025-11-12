#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int n,a[1000010],x,ans,s,ma,f;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n>20){
		ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]){
				x++;
			}
		}
		for(int i=1;i<=x;i++){
			ans*=2;
		}
		cout<<(ans+M-x*(x-1)/2-n-1)%M;
	}else{
		for(int i=1;i<(1<<n);i++){
			s=0;ma=0;f=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					s+=a[j+1];
					ma=max(ma,a[j+1]);
					f++;
				}
			}
			if(f>=3&&s>ma*2){
				ans=(ans+1)%M;
			}
		}
		cout<<ans;
	}
	return 0;
}
