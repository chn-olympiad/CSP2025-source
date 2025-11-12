#include <bits/stdc++.h>
using namespace std;
long long n,a[50005],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>3 && n<=100){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]){
						cnt++;
						cnt%=998244353;
					}
				}
			}
		}
		cout<<cnt*3%998244353;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
