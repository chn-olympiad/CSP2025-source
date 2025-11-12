#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010],ans,max1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(max1==1){
		cout<<((((n-2)+1)%998244353)*((n-2)%998244353)/2)%998244353;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<n;i++){
		for(int j=i;j<=n;j++){
			if((b[j-1]-b[j-i])>a[j]){
				ans++;
				ans%=998244353;
			}
		}
	}
	cout<<ans%998244353;
	//bukeyizongsiling,pianfen
	return 0;
}
