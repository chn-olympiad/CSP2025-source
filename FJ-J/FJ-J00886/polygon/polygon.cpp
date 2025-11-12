#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}else if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<"1";
			return 0;
		}
	}
	for(int i=1;i<=n-2;i++){
		long long maxx=0,sum=0;
		for(int j=i+1;j<=n-1;j++){
			for(int l=j+1;l<=n;l++){
				if(a[i]+a[j]+a[l]>2*max({a[i],a[j],a[l]})){
					cnt++;
				}
			}
		}
	}
	cout<<3*cnt%998244353;
	return 0;
}
