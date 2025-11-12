#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005],maxx=-1,minn,b,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn||i==1){
			minn=a[i];
		}
		if(a[i]>maxx){
			maxx=a[i];
		}
		if(a[i]==1){
			sum++;
		}
	}
	if(maxx==1&&minn==1){
		if(k<2){
			if(k%2==1){
				for(int i=1;i<=n;i+=2){
					ans+=n%i;
				}
			}else{
				for(int i=2;i<=n;i+=2){
					ans+=n%i;
				}
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}else if(maxx==1&&minn==0){
		if(k==1){
			for(int i=1;i<=sum;i+=2){
				ans+=n%i;
			}
			cout<<ans;
		}else if(k==0){
			for(int i=2;i<=sum;i+=2){
				ans+=n%i;
			}
			for(int i=2;i<=n-sum;i+=2){
				ans+=n%i;
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}else{
		
	}
	return 0;
}
