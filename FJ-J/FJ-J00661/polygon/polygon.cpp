#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans;
int mj(int s){
	if(s>n)return 0;
	int maxx=0,sum=0;
	for(int i=1;i<=n-s+1;i++){
		maxx=0;
		sum=0;
		for(int j=i;j<=i+s-1;j++){
			sum+=a[j];
			maxx=max(maxx,a[j]);
		}
		if(sum>2*maxx)ans++;
	}
	mj(s+1);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<0;
	else if(n==3)cout<<1;
	else{
		mj(3);
	    cout<<ans;
	}
	return 0;
}
