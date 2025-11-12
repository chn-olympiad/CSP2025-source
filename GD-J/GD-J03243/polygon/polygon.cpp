#include <bits/stdc++.h>
using namespace std;
bool flag;
int n,num,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out"."w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=true;
		num+=a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(!flag){
		long long ans;
		for(int i=1;i<=n-3;i++){
			long long ans_f=1;
			for(int j=1;j<=i;j++){
				ans_f*=(n-j+1)/j%998244353;
			}
			ans+=ans_f%998244353;
		}
		cout<<ans+1;
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(num>2*a[3]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
