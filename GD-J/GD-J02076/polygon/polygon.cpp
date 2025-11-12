#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s;
void f(int summ,short lastnumi,short nums){
	if(nums>2){
		if(summ>a[lastnumi]*2){
			++s;
			s%=mod;
		}
	}
	for(short i=lastnumi+1;i<n;++i){
		f(summ+a[i],i,nums+1);
	}
}
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;++i){
		f(a[i],i,1);
	}
	cout<<s;
	return 0;
}
