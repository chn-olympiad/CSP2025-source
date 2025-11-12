#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
long long n,a[N],mx=0,ans=0,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(sum<=mx*2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	mx*=2;
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
} 