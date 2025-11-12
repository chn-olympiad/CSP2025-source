#include<bits/stdc++.h>
using namespace std;
long long sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopne("polygon.out","w",stdout);
	long long a,b;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		sum+=b;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
