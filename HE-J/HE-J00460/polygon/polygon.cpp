#include<bits/stdc++.h>
using namespace std;
long long n,a[1000],s=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long m=1,o=0,ma;
		m++;
		o+=a[i];
		if(a[i]>ma)ma=a[i];
		if(m>=3){
			if(o>ma*2)s++;
		}
	}
	cout<<s;
}
