#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,a[5010],p=0,maxn=-1,o=0;
	long long l[5010];
	bool k=true;
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p+=a[i];
			maxn=max(a[i],maxn);
		}
		if(p>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=1){
				k=false;
			}
		}
		if(k){
			for(int i=n-2;i>=1;i--){
				l[n-1-i]+=(1+i)*i/2;
				if(l[n-1-i]>=N){
					l[n-1-i]%=N;
				}
			}
			for(int i=1;i<=n-2;i++){
				o+=l[i]*i;
				if(o>=N){
					o%=N;
				}
			}
			cout<<o;
		}
	}
	return 0;
}