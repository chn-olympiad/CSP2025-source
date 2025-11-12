#include<bits/stdc++.h>
using namespace std;
int n,a1[5005];
long long sum[5005],ans;
void f1(){
	sort(a1+1,a1+n+1);
	if(a1[1]+a1[2]>a1[3]){
		ans++;
	}
	cout<<ans%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	if(n<=3){
		f1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	return 0;
}
