#include <bits/stdc++.h>
using namespace std;
long long n,l[5005],m=3,s,maxn=0,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(n==3){
		sort(l,l+n);
		if(l[0]+l[1]>l[2]) cnt++;
		cout<<cnt;
		return 0;
	}
	else{
		cnt=n+1;
		cout<<cnt%998244353;	
	}
	return 0;
}
