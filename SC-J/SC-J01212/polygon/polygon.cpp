#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,a[5005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool s=0;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			s=1;
		}
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		int mx=max(a[1],max(a[2],a[3])),t=a[1]+a[2]+a[3];
		if(2*mx<t){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(s==0){
		long long t=0;
		for(int i=3;i<=n;i++){
			long long h=1;
			for(int j=n;j>n-i;j--){
				h=h*j/(n-j+1)%N;
			}
			t+=h;
			t%=N;
		}
		cout<<t;
	}else{
		cout<<0;
	}
	return 0;
}
