#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,sum,m=1;
long long a[100000],b[100000],c[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if (max(max(a[1],a[2]),a[3])<max(a[1]+a[2],max(a[1]+a[3],a[2]+a[3]))){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int j=2;j<=n;j++){
				m*=j;
			}
		for(int i=3;i<=n;i++){
			 b[i]=1;
			 c[i]=1;
			for(int j=2;j<=i;i++){
				b[i]*=j;
				
			}for(int j=2;j<=n-i;j++){
				c[i]*=j;
			}
		}
		for(int i=1;i<=n;i++){
			sum+=m/(b[i]*c[i]);
			sum%=998244353;
		}
		cout<<sum;
	}
	return 0;
}

