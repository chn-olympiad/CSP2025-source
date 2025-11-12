#include<bits/stdc++.h>
using namespace std;
int n,a[50000],ans=0;
void f( int sum , int maxx , int turn ,int num ){
	if(n-turn+1+num<3)return;
	if(turn>n){
		if(num>=3&&sum>maxx*2){
		    ans++,ans%=998244353 ; 
		}return ;
	}
	f( sum+a[turn], a[turn] , turn+1 ,num+1);//ัก 
	f( sum , maxx , turn+1 ,num);//ฒปัก
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f(0,0,1,0);
	cout<<ans;
	return 0;
}
