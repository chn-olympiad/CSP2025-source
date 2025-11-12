#include<bits/stdc++.h>
using namespace std;
long long a[5002];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a1=0,s,ma,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) a1=-1;
	}
	if(n==3){
		s1=ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
			s1=s1+a[i];
		}
		if((s1-ma)>ma){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(a1==0){
		s=1;
		for(int i=1;i<=n-1;i++){
			s=(s*2)%998244353;
		}
		cout<<s-1-n+1;
	}
	return 0;
}
