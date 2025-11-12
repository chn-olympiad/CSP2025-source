//xor  //AC 1 2 3 4 5 6 

#include<iostream>
using namespace std;
using ll = long long;

ll num[500010];//max n =  5*10^5
ll x[500010];//max n =  5*10^5  前缀和（亦或版） 

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ll n,k;
	cin>>n>>k;
	
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&num[i]);
	} 
	//input
	
	for(ll i = 1;i<=n;i++){
		x[i] = x[i-1]^num[i];
	}//前缀和
	
	ll cnt = 0;
	ll max_left = 1;//最大左值 
	
	for(ll r = 1;r<=n;r++){//[l,r]
		for(ll l = max_left;l<=r;l++){
			ll rx = x[r] ^ x[l-1];
			if(rx == k){//有效区间 
				cnt ++;
				//cout<<l<<' '<<r<<" rx: "<<rx<<endl;////
				//r = r;//更新到[r+1,r+1]防止香蕉 
				l = r;//下回合自动加到r+1 
				max_left = r+1;
			}
		}
	}
	
	cout<<cnt;
	
	//我去牛逼！！！！！ 300分  还有109分钟  我治好了抑郁症 
}
