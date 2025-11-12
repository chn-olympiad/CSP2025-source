#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int a[51400],ans,alllen,large;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=j;k<=i && k+i<=n;k++)
				alllen+=a[k];
			if(alllen>a[n-1]*2)ans++;
		}
	}
	cout<<ans;
	return 0;
}
