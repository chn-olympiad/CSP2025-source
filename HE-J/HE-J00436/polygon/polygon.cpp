#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,sum=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if((a[1]+a[2])>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	ans+=n*(n-1)*(n-2)/3/2;
	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++) sum*=(n-j);
		for(int j=i;j>=2;j--) sum/=j;
		ans+=sum;
		sum=1;
	}
	cout<<ans<<"\n";
	return 0;
}
