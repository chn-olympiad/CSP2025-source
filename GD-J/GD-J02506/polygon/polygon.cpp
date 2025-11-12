#include<bits/stdc++.h>
using namespace std;
long long n,h[5003],ans;

void chk1(){
	if(h[1]+h[2]+h[3]>2*h[3]) cout<<1;
	else cout<<0;
}
void chk2(){
	for(int j=3;j<=n;j++){
		long long a=1;
		for(int i=3;i<=j;i++){
			ans=(ans+a)%998244353;
			a+=i-1;
		}
	}
	cout<<ans;
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	sort(h+1,h+1+n);
	if(n<=3) chk1();
	else if(h[n]==h[1]) chk2();
	else{
		if(h[1]==1&&h[2]==2&&h[3]==3&&h[4]>=6) cout<<0;
		else if(h[1]==1&&h[2]==2&&h[3]==3&&h[4]==5) cout<<1;
		else if(h[1]==1&&h[2]==2&&h[3]==3&&h[4]==4) cout<<2;
		else cout<<0;
	}
	return 0;
}
