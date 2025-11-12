#include<bits/stdc++.h>
using namespace std;
long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i=m;i>=1;i--){
		sum*=m;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
