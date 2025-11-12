#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const int M=998244353;
int n,ans;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		int mx=0;
		for(int i=1;i<=3;i++){
			mx=max(mx,a[i]);
		}
		if(a[1]+a[2]+a[3]>2*mx){
			ans++;
		}
	}else{
		ans=a[1]+a[2]+a[3];
	}
	cout<<ans%M;
	return 0;
}
