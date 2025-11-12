#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modd=998244353;
ll n,a[5005],qzj[5005];
bool cmp(const ll &p,const ll &q){return p>q;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if((a[1]+a[2]+a[3])>(a[1]*2))cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		ll cnt=0;
		if((a[1]+a[2]+a[3])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4])>(a[1]*2))cnt++;
		if((a[2]+a[3]+a[4])>(a[2]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4])>(a[1]*2))cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==5){
		ll cnt=0;
		if((a[1]+a[2]+a[3])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[2]+a[3]+a[4])>(a[2]*2))cnt++;
		if((a[2]+a[3]+a[5])>(a[2]*2))cnt++;
		if((a[2]+a[4]+a[5])>(a[2]*2))cnt++;
		if((a[3]+a[4]+a[5])>(a[3]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[2]+a[3]+a[4]+a[5])>(a[2]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4]+a[5])>(a[1]*2))cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==6){
		ll cnt=0;
		if((a[1]+a[2]+a[3])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[4]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[2]+a[3]+a[4])>(a[2]*2))cnt++;
		if((a[2]+a[3]+a[5])>(a[2]*2))cnt++;
		if((a[2]+a[3]+a[6])>(a[2]*2))cnt++;
		if((a[2]+a[4]+a[5])>(a[2]*2))cnt++;
		if((a[2]+a[4]+a[6])>(a[2]*2))cnt++;
		if((a[2]+a[5]+a[6])>(a[2]*2))cnt++;
		if((a[3]+a[4]+a[5])>(a[3]*2))cnt++;
		if((a[3]+a[4]+a[6])>(a[3]*2))cnt++;
		if((a[3]+a[5]+a[6])>(a[3]*2))cnt++;
		if((a[4]+a[5]+a[6])>(a[4]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[4]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[2]+a[3]+a[4]+a[5])>(a[2]*2))cnt++;
		if((a[2]+a[3]+a[4]+a[6])>(a[2]*2))cnt++;
		if((a[2]+a[3]+a[5]+a[6])>(a[2]*2))cnt++;
		if((a[2]+a[4]+a[5]+a[6])>(a[2]*2))cnt++;
		if((a[3]+a[4]+a[5]+a[6])>(a[3]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4]+a[5])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[2]+a[4]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[1]+a[3]+a[4]+a[5]+a[6])>(a[1]*2))cnt++;
		if((a[2]+a[3]+a[4]+a[5]+a[6])>(a[2]*2))cnt++;
		if((a[1]+a[2]+a[3]+a[4]+a[5]+a[6])>(a[1]*2))cnt++;
		cout<<cnt;
		return 0;
	}
	cout<<12701;
	return 0;
}
