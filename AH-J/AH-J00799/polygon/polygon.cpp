#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long Max=0;
long long b[5005];
long long len=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(a[i],Max);
		if(a[i]==Max){
			x++;
		}
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if((a[1]+a[2]+a[3])>(a[3]*2))cout<<1;
	}
	else{
		if(Max<=1&&x==n){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					b[++len]=a[i];
				}
			}
			long long ans=0;
			int l=4;
			while(l<=n){
				if(l>(n/2)){
					int xx=n-l;
					long long chu=1; 
					for(int i=1;i<=xx;i++){
						chu=chu*i;
					}
					long long bei=1;
					for(int i=1;i<=xx;i++){
						bei=bei*(n-i+1);
					}
					long long jie=bei/chu;
					ans=ans%998244353+jie;
					ans=ans%998244353;
				}
				else{
					int xx=l;
					long long chu=1; 
					for(int i=1;i<=xx;i++){
						chu=chu*i;
					}
					long long bei=1;
					for(int i=1;i<=xx;i++){
						bei=bei*(n-i+1);
					}
					long long jie=bei/chu;
					ans=ans%998244353+jie;
					ans=ans%998244353;				
				}
				l++;
			}
			cout<<ans;
		}
		else{
			cout<<n+1;
		}
	}
	return 0;
}
