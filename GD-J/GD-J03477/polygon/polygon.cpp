#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,len[5050],flag=1,ans;
ll zhuhe(ll a,ll b){
	ll l=1,r=1;
	for(int i=0;i<b;i++){
		l=l*(a-i);
		r=r*(i+1);
	}return l/r;
}
void teshu1(){
	if(n<3){
		cout<<0<<endl;
		return;
	}if((len[1]+len[2]<=len[3])||(len[2]+len[3]<=len[1])||(len[1]+len[3]<=len[2])){
		cout<<0<<endl;
		return;
	}cout<<1<<endl;
	return;
}
void teshu2(){
	for(int i=3;i<=n;i++){
		ans=(ans+zhuhe(n,i))%998244353;
	}cout<<ans%998244353<<endl;
	return;
}
void buhui(){
	cout<<0<<endl;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>len[i];
	if(n<=3){
		teshu1();
		return 0;
	}
	for(int i=1;i<=n;i++)
	    if(len[i]!=1)flag=0;
	if(flag){
		teshu2();
		return 0;
	}else{
		buhui();
		return 0;
	}
	return 0;
}
