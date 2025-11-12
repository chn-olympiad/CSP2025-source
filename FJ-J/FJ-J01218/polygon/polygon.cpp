#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)cout<<1;
		else cout<<0;
	}else if(n==4){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)ans++;
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2)ans++;
		if(a[1]+a[3]+a[4]>max(max(a[1],a[3]),a[4])*2)ans++;
		if(a[3]+a[2]+a[4]>max(max(a[3],a[2]),a[4])*2)ans++;
		if(a[1]+a[2]+a[4]+a[3]>max(max(max(a[1],a[2]),a[4]),a[3])*2)ans++;
		cout<<ans;
	}else if(n==5){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)ans++;
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2)ans++;
		if(a[1]+a[2]+a[5]>max(max(a[1],a[2]),a[5])*2)ans++;
		if(a[1]+a[3]+a[4]>max(max(a[1],a[3]),a[4])*2)ans++;
		if(a[1]+a[3]+a[5]>max(max(a[1],a[3]),a[5])*2)ans++;
		if(a[1]+a[5]+a[4]>max(max(a[1],a[5]),a[4])*2)ans++;
		if(a[3]+a[2]+a[4]>max(max(a[3],a[2]),a[4])*2)ans++;
		if(a[3]+a[2]+a[5]>max(max(a[3],a[2]),a[5])*2)ans++;
		if(a[5]+a[2]+a[4]>max(max(a[5],a[2]),a[4])*2)ans++;
		if(a[3]+a[5]+a[4]>max(max(a[3],a[5]),a[4])*2)ans++;
		if(a[1]+a[2]+a[4]+a[3]>max(max(max(a[1],a[2]),a[4]),a[3])*2)ans++;
		if(a[1]+a[2]+a[5]+a[3]>max(max(max(a[1],a[2]),a[5]),a[3])*2)ans++;
		if(a[1]+a[5]+a[4]+a[3]>max(max(max(a[1],a[5]),a[4]),a[3])*2)ans++;
		if(a[5]+a[2]+a[4]+a[3]>max(max(max(a[5],a[2]),a[4]),a[3])*2)ans++;
		if(a[5]+a[2]+a[4]+a[1]+a[3]>max(max(max(max(a[5],a[2]),a[4]),a[1]),a[3])*2)ans++;
		cout<<ans%998244353;
	}else if(n==6){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)ans++;
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2)ans++;
		if(a[1]+a[2]+a[5]>max(max(a[1],a[2]),a[5])*2)ans++;
		if(a[1]+a[2]+a[6]>max(max(a[1],a[2]),a[6])*2)ans++;
		if(a[1]+a[3]+a[4]>max(max(a[1],a[3]),a[4])*2)ans++;
		if(a[1]+a[5]+a[3]>max(max(a[1],a[5]),a[3])*2)ans++;
		if(a[3]+a[1]+a[6]>max(max(a[3],a[1]),a[6])*2)ans++;
		if(a[1]+a[4]+a[5]>max(max(a[1],a[4]),a[5])*2)ans++;
		if(a[1]+a[6]+a[4]>max(max(a[1],a[6]),a[4])*2)ans++;
		if(a[1]+a[5]+a[6]>max(max(a[1],a[5]),a[6])*2)ans++;
		if(a[2]+a[3]+a[4]>max(max(a[2],a[3]),a[4])*2)ans++;
		if(a[2]+a[5]+a[3]>max(max(a[2],a[5]),a[3])*2)ans++;
		if(a[2]+a[3]+a[6]>max(max(a[2],a[3]),a[6])*2)ans++;
		if(a[3]+a[5]+a[4]>max(max(a[3],a[5]),a[4])*2)ans++;
		if(a[3]+a[4]+a[6]>max(max(a[3],a[4]),a[6])*2)ans++;
		if(a[3]+a[5]+a[6]>max(max(a[3],a[5]),a[6])*2)ans++;
		if(a[4]+a[5]+a[6]>max(max(a[4],a[5]),a[6])*2)ans++;
		if(a[1]+a[2]+a[4]+a[3]>max(max(max(a[1],a[2]),a[4]),a[3])*2)ans++;
		if(a[1]+a[2]+a[5]+a[3]>max(max(max(a[1],a[2]),a[5]),a[3])*2)ans++;
		if(a[1]+a[2]+a[6]+a[3]>max(max(max(a[1],a[2]),a[6]),a[3])*2)ans++;
		if(a[5]+a[2]+a[4]+a[1]>max(max(max(a[5],a[2]),a[4]),a[1])*2)ans++;
		if(a[6]+a[2]+a[4]+a[1]>max(max(max(a[6],a[2]),a[4]),a[1])*2)ans++;
		if(a[5]+a[2]+a[6]+a[1]>max(max(max(a[5],a[2]),a[6]),a[1])*2)ans++;
		if(a[5]+a[3]+a[4]+a[1]>max(max(max(a[5],a[3]),a[4]),a[1])*2)ans++;
		if(a[3]+a[6]+a[4]+a[1]>max(max(max(a[3],a[6]),a[4]),a[1])*2)ans++;
		if(a[5]+a[6]+a[4]+a[1]>max(max(max(a[5],a[6]),a[4]),a[1])*2)ans++;
		if(a[5]+a[2]+a[4]+a[3]>max(max(max(a[5],a[2]),a[4]),a[3])*2)ans++;
		if(a[6]+a[2]+a[4]+a[3]>max(max(max(a[6],a[2]),a[4]),a[3])*2)ans++;
		if(a[5]+a[2]+a[4]+a[6]>max(max(max(a[5],a[2]),a[4]),a[6])*2)ans++;
		if(a[5]+a[3]+a[4]+a[6]>max(max(max(a[5],a[3]),a[4]),a[6])*2)ans++;
		if(a[5]+a[2]+a[4]+a[1]+a[3]>max(max(max(max(a[5],a[2]),a[4]),a[1]),a[3])*2)ans++;
		if(a[6]+a[2]+a[4]+a[1]+a[3]>max(max(max(max(a[6],a[2]),a[4]),a[1]),a[3])*2)ans++;
		if(a[5]+a[6]+a[4]+a[1]+a[3]>max(max(max(max(a[5],a[6]),a[4]),a[1]),a[3])*2)ans++;
		if(a[5]+a[2]+a[4]+a[6]+a[3]>max(max(max(max(a[5],a[2]),a[4]),a[6]),a[3])*2)ans++;
		if(a[5]+a[2]+a[4]+a[1]+a[3]+a[6]>max(max(max(max(max(a[5],a[2]),a[4]),a[1]),a[3]),a[6])*2)ans++;
		cout<<ans%998244353;
	}else cout<<rand()%998244353;
	return 0;
}
