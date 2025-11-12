#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=5005;
int n,a[N],ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<3) cout<<0;
	else if(n==3){
		if((a[1]+a[2]+a[3])>2*a[1])cout<<1;
		else cout<<0;
	}else if(n==4){
		if((a[1]+a[2]+a[3])>2*a[1])++ans;
		if((a[1]+a[3]+a[4])>2*a[1])++ans;
		if((a[2]+a[3]+a[4])>2*max(a[2],max(a[3],a[4])))++ans;
		if((a[1]+a[2]+a[3]+a[4])>2*a[1])++ans;
		cout<<ans;
	}else if(n==5){
		if((a[1]+a[2]+a[3])>2*a[1])++ans;
		if((a[1]+a[2]+a[4])>2*a[1])++ans;
		if((a[1]+a[2]+a[5])>2*a[1])++ans;
		if((a[1]+a[3]+a[4])>2*a[1])++ans;
		if((a[1]+a[3]+a[5])>2*a[1])++ans;
		if((a[1]+a[4]+a[5])>2*a[1])++ans;
		if((a[2]+a[3]+a[4])>2*max(a[2],max(a[3],a[4])))++ans;
		if((a[2]+a[3]+a[5])>2*max(a[2],max(a[3],a[5])))++ans;
		if((a[2]+a[4]+a[5])>2*max(a[2],max(a[4],a[5])))++ans;
		if((a[3]+a[4]+a[5])>2*max(a[3],max(a[4],a[5])))++ans;
		if((a[1]+a[2]+a[3]+a[4])>2*a[1])++ans;
		if((a[1]+a[2]+a[3]+a[5])>2*a[1])++ans;
		if((a[1]+a[2]+a[4]+a[5])>2*a[1])++ans;
		if((a[1]+a[3]+a[4]+a[5])>2*a[1])++ans;
		if((a[2]+a[3]+a[4]+a[5])>2*max(a[2],max(a[3],max(a[4],a[5]))))++ans;
		if((a[1]+a[2]+a[3]+a[4]+a[5])>2*a[1])++ans;
		cout<<ans;
	}else if(n==6){
		if((a[1]+a[2]+a[3])>2*a[1])++ans;
		if((a[1]+a[2]+a[4])>2*a[1])++ans;
		if((a[1]+a[2]+a[5])>2*a[1])++ans;
		if((a[1]+a[2]+a[6])>2*a[1])++ans;
		if((a[1]+a[3]+a[4])>2*a[1])++ans;
		if((a[1]+a[3]+a[5])>2*a[1])++ans;
		if((a[1]+a[3]+a[6])>2*a[1])++ans;
		if((a[1]+a[4]+a[5])>2*a[1])++ans;
		if((a[1]+a[4]+a[6])>2*a[1])++ans;
		if((a[1]+a[5]+a[6])>2*a[1])++ans;
		if((a[2]+a[3]+a[4])>2*max(a[2],max(a[3],a[4])))++ans;
		if((a[2]+a[3]+a[5])>2*max(a[2],max(a[3],a[5])))++ans;
		if((a[2]+a[3]+a[6])>2*max(a[2],max(a[3],a[6])))++ans;
		if((a[2]+a[4]+a[5])>2*max(a[2],max(a[4],a[5])))++ans;
		if((a[2]+a[4]+a[6])>2*max(a[2],max(a[4],a[6])))++ans;
		if((a[2]+a[5]+a[6])>2*max(a[2],max(a[5],a[6])))++ans;
		if((a[3]+a[4]+a[5])>2*max(a[3],max(a[4],a[5])))++ans;
		if((a[3]+a[4]+a[6])>2*max(a[3],max(a[4],a[6])))++ans;
		if((a[3]+a[5]+a[6])>2*max(a[3],max(a[5],a[6])))++ans;
		if((a[4]+a[5]+a[6])>2*max(a[4],max(a[5],a[6])))++ans;
		if((a[1]+a[2]+a[3]+a[4])>2*a[1])++ans;
		if((a[1]+a[2]+a[3]+a[5])>2*a[1])++ans;
		if((a[1]+a[2]+a[3]+a[6])>2*a[1])++ans;
		if((a[1]+a[2]+a[4]+a[5])>2*a[1])++ans;
		if((a[1]+a[2]+a[4]+a[6])>2*a[1])++ans;
		if((a[1]+a[2]+a[5]+a[6])>2*a[1])++ans;
		if((a[1]+a[3]+a[4]+a[5])>2*a[1])++ans;
		if((a[1]+a[3]+a[4]+a[6])>2*a[1])++ans;
		if((a[1]+a[3]+a[5]+a[6])>2*a[1])++ans;
		if((a[1]+a[4]+a[5]+a[6])>2*a[1])++ans;
		if((a[2]+a[3]+a[4]+a[5])>2*max(a[2],max(a[3],max(a[4],a[5]))))++ans;
		if((a[2]+a[3]+a[4]+a[6])>2*max(a[2],max(a[3],max(a[4],a[6]))))++ans;
		if((a[2]+a[3]+a[5]+a[6])>2*max(a[2],max(a[3],max(a[5],a[6]))))++ans;
		if((a[2]+a[4]+a[5]+a[6])>2*max(a[2],max(a[4],max(a[5],a[6]))))++ans;
		if((a[3]+a[4]+a[5]+a[6])>2*max(a[3],max(a[4],max(a[5],a[6]))))++ans;
		if((a[1]+a[2]+a[3]+a[4]+a[5])>2*a[1])++ans;
		if((a[1]+a[2]+a[3]+a[4]+a[6])>2*a[1])++ans;
		if((a[1]+a[2]+a[3]+a[5]+a[6])>2*a[1])++ans;
		if((a[1]+a[2]+a[4]+a[5]+a[6])>2*a[1])++ans;
		if((a[1]+a[3]+a[4]+a[5]+a[6])>2*a[1])++ans;
		if((a[2]+a[3]+a[4]+a[5]+a[6])>2*max(a[2],max(a[3],max(a[4],max(a[5],a[6])))))++ans;
		cout<<ans;
	}else cout<<ans%MOD;
	return 0;
}

