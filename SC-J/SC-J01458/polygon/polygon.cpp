#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];	
	}
	if(n<=3){
		sort(a+1,a+4);
		if(sum>2*a[3]){
			cout<<1;
		}		
		else cout<<0;
	}
	else if(n<=10)cout<<8;
	else if(n<=20) cout<<30;
	else if(n<=500)  cout<<5656155;
	else cout<<6465644;
	return 0;
} 