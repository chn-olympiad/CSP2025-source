#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],ans;
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
	}
	else if(n==3){
		long long maxn=0,sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>maxn*2) ans=1;
		else ans=0;
	}
	cout<<ans;
	return 0;
}
