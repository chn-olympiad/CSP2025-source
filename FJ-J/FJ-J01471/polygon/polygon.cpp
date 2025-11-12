#include <bits/stdc++.h>
using namespace std;
int a[5200];
int n;
int co;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int num=a[i]+a[i+1];
		for(int j=i+2;j<=n-i;j++)
			if((num+a[j])>(a[i]*2)){
				co++;
				num+=a[j];
			}
	}
	cout<<co;
	return 0;
}
