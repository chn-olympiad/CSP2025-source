#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,a[N],maxx=-1,ans,sum1=1,sum2=1;
bool f=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(n<3){
		cout <<0;
	}
	else if(n==3){
		maxx=max(maxx,max(a[1],max(a[2],a[3])));
		if(a[1]+a[2]+a[3]>maxx){
			cout <<1;
		}
		else {
			cout <<0;
		}
	}
	else if(f){
		for (int i=3;i<=n;i++){
			for (int j=1;j<=i;j++){
				sum1*=(n-j+1);
				sum2*=j;
				sum1%=998244353;
				sum2%=998244353;
			}
			ans+=(sum1/sum2)%998244353;
			sum1=1;
			sum2=1;
		}
		cout <<ans%998244353;
	}
	return 0;
}
