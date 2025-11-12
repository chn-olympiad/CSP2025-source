#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum1=0;
	int sum2=0;
	int a[5010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			sum1+=a[j];
		} 
		if(a[i]*2<sum1){
			sum2++;
		}
	}
	cout<<sum2%998244353;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
