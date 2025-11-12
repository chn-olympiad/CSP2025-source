#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5010],s[5010],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	if(n<=3){
		if(a[1]+a[2]<=a[3])cout<<0;
		else cout<<1;
		return 0;
	}
	else cout<<n;
	return 0;
}

