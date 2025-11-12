#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int a[N];
int sum[N];
long long res,ans;
int main(){

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
