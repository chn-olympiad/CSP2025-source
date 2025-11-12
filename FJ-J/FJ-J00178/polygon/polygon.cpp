#include<iostream>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	do{
		for(int i=1;i<=n;i++){
			ans++;
		}
		
	}while(next_permutation(a,a+n));
	cout<<ans%998244353;
	return 0;
}
