#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long b[5010];
long long zz=0;
void ss(int n,int x,int z)
{
	z-=n;
	if(z<0){
		zz=zz+(pow(2,x-1));
		zz=zz%998244353;
		return ;
	}
	else {
		for(int i=x-1;i>=1;i--){
			if(b[i]>z)ss(a[i],i,z);
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=n;i>=3;i--){
		if(b[i-1]>a[i]) ss(a[i],i,2*a[i]);
	}
	cout<<zz;
	return 0;
}

