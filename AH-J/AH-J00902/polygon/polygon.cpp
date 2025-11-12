#include<bits/stdc++.h>
using namespace std;
int a[5500],b[5500],ans,b1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b1=max(b1,a[i]);
	}
	if(n==3){
		int a1=a[1]+a[2]+a[3];
		if(a1>b1*2)
		cout<<1;
		else
		cout<<0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				b[j]=b[j]+b[j-1];
				b[j]=b[j]%998244353;
			}
			b[1]=i%998244353;
			b[i]=1;
		}
		for(int i=3;i<=n;i++){
			ans=ans+b[i];
			ans=ans%998244353;
		}
		cout<<ans;
	}
	return 0;
}
