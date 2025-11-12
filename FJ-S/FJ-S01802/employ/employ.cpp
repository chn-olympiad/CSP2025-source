#include<bits/stdc++.h>
using namespace std;
long long a,s,d,f,g,h,j,k,l,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>s>>a;
	d=1;
	for(int i=0,i<s;i++){
		d*=(s-i);
		d%=998244353;
	}
	cout<<d;
}
