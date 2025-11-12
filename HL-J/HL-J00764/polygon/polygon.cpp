#include<bits/stdc++.h>
using namespace std;
const int x=1e4;
int a[x],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(2*(a[i]+a[j])>a[k])
				sum++;
			}
		}
	}
	cout<<sum%998244353;
return 0;
}
