#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,MAD=998244353;
int n,a[N],cnt=1;
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-2;i++){
		long long t=a[i]+a[i+1]+a[i+2];
		if(t>a[i]*2){
			ans++;
			ans+=(n-i-1)*(n-i-2)/2;
		}
	}
	cout<<(ans%MAD);
	return 0;
}
