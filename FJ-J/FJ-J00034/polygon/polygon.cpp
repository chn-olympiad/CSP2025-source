#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=998244353;

int n;ll ans;
int a[5007];
ll c(int x,int y){
	y=min(y,x-y);
	int a1=1,a2=1;
	for(int i=1;i<=y;i++){
		a1*=(x-i+1)%M,a2*=i%M;
	}
	return a1/a2;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}else{
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=M;
		}
		cout<<ans;
	}
}
