#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s;
long long b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}else{
		long long z=1; b[1]=z;
		for(int i=2;i<=n;i++){
			z*=i;
			b[i]=z%998244353;	
		}for(int i=3;i<=n;i++){
			s+=b[n]/b[n-i]/b[i];
		}cout<<s;
	}
	return 0;
}
