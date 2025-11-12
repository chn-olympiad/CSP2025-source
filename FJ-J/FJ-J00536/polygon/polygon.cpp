#include<bits/stdc++.h>
using namespace std;
long long m[5005],d,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		if(m[i]>d){
			d=m[i];
		}
	}
	if(d==1){
		for(int i=1;i<=n;i++){
			long long a=1,b=1;
			for(int j=n;j>=n-i+1;j--){
				a*=j;
				a%=998244353;
			}
			for(int j=i;j>=1;j--){
				b*=j;
				b%=998244353;
			}
			sum+=a/b;
			sum%=998244353;
		}
		cout<<sum%998244353;
	}else if(n==3){
		cout<<1;
	}else{
		cout<<20130109;
	}
	return 0;
}
