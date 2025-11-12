#include<bits/stdc++.h>
using namespace std;
long long t=0,t1=1,t2=1,n,a[5050],s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1);
	if (n==3){
		if (a[3]<a[1]+a[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if (s==n){
		for (int i=3;i<=n;i++){
			t1=1,t2=1;
			for (int j=i+1;j<=n;j++){
				t1*=j;
				t1%=998244353;
			}
			for (int j=1;j<=n-i;j++){
				t2*=j;
				t2%=998244353;
			}
			cout<<t1<<" "<<t2<<"\n";
			t+=((t1/t2)%998244353);
		}
		cout<<t;
	}
	return 0;
}
//RP++
