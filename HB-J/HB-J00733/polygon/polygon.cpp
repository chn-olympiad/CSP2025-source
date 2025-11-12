#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,te;
long long ans;
long long b=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3)cout<<"0";
	else if(n==3){
		if(maxn*2<(a[1]+a[2]+a[3]))cout<<"1";
		else cout<<"0";
	}else if(maxn==1){
		long long ans=0;
		for(int i=n;i>=3;i--){
			for(int j=1;j<=i-2;j++){
				ans+=(1ll*i*(i-1)/2)%b;
				ans%=b;
			}
		}
		cout<<ans%b;
	}else{
		for(int z=0;z<=1;z++){
			for(int y=0;y<=1;y++){
				for(int c=0;c<=1;c++){
					for(int d=0;d<=1;d++){
						for(int e=0;e<=1;e++){
							te=0;
							int k=z*a[1],l=y*a[2],m=c*a[3],o=d*a[4],p=e*a[5];
							te=max(te,k);
							te=max(te,l);
							te=max(te,m);
							te=max(te,o);
							te=max(te,p);
							if(te*2<k+l+m+o+p){
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans%b;
	}
	return 0;
}
