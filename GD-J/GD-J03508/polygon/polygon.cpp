#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool lo(ll n){
	int b=0;
//	cout<<n<<' ';
	while(n){
		if(n%2==1)b++;
		n/=2;
	}
//	cout<<b<<endl;
	if(b>=3)return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,a[5005],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//cout<< (1<<n);
	for(ll i=1;i<=(1<<n)-1;i++){
		if(!lo(i))continue;
		ll x=i,sum=0;
		ll maxn=0;
		for(int j=1;x!=0;j++,x/=2){
		//	cout<<x<<' '<<j<<endl;
			if(x%2==1){
				sum+=a[j];
				if(a[j]>maxn)maxn=a[j];
			}
		}
	//	cout<<sum<<' '<<maxn<<endl;
		if(sum>maxn*2)ans++;
	}
	cout<<ans%998244353;
	return 0;
} 
/*
CCF CSP-J/S 2025 RP++
当前题目：J T4
它还是那么爱小木棍 
赛时预估：最高40pts 大约20pts 保底10pts 黄~绿题 
版权所有 请勿翻录
陈彦羽
2025/11/1
惠州中学
*/ 
