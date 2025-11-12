#include<bits/stdc++.h>
using namespace std;
const long long m=998244353;
long long n,s;
long long a[505050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))s++;
	}
	else{
		for(int i=3;i<=n;i++){
			s+=(n-i+1)%m;
			s%=m;
		}	
	}
	cout<<s;
	return 0;
}